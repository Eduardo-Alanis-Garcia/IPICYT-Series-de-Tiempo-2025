library(EWSmethods)
library(tidyverse)
library(patchwork)

data("simTransComms")
data("CODrecovery")

plot(x = CODrecovery$scenario2$time, y = CODrecovery$scenario2$biomass, type = "l", xlab = "Year", ylab = "Abundance", main = "Recovering cod population")
ggplot(CODrecovery$scenario2,            # el data frame
       aes(x = time, y = biomass)) +     # mapeo estético
  geom_line(size = 1) +                  # línea continua
  labs(
    title = "Recovering cod population",
    x = "Year",
    y = "Abundance"
  ) +
  theme_minimal(base_size = 14) 



pre_CODrecovery <- subset(CODrecovery$scenario2,time < inflection_pt)
pre_simTransComms <- subset(simTransComms$community1,time < inflection_pt)

rolling_ews_eg <- uniEWS(data = pre_simTransComms[,c(2,5)],
                         metrics = c("ar1","SD","skew"),
                         method = "rolling",winsize = 50)

plot(rolling_ews_eg,  y_lab = "Density")




expanding_ews_eg <- uniEWS(data = pre_simTransComms[,c(2,5)],
                           metrics = c("ar1","SD","skew"),
                           method = "expanding",
                           burn_in = 50,
                           threshold = 2)

plot(expanding_ews_eg, y_lab = "Density")




trait_ews_eg = uniEWS(data = pre_CODrecovery[,c(2,3)],
                       metrics = c("ar1","SD","trait"), #note "trait" is provided here
                       method = "expanding",
                       trait = pre_CODrecovery$mean.size, #and here
                       burn_in = 15, #small burn_in due to shorter time series
                       threshold = 2)
plot(trait_ews_eg, y_lab = "Density", trait_lab = "Mean size (g)")



multi_ews_eg <- multiEWS(data = pre_simTransComms[,2:7],
                         metrics = c("meanAR","maxAR","meanSD","maxSD","eigenMAF","mafAR","mafSD","pcaAR","pcaSD","eigenCOV","maxCOV","mutINFO"),
                         method = "rolling",
                         winsize = 50)

plot(multi_ews_eg)



multi_ews_eg2 <- multiEWS(data = pre_simTransComms[,2:7],
                          method = "expanding",
                          burn_in = 50,
                          threshold = 2)
plot(multi_ews_eg2)
