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


















#################
library(EWSmethods)
library(tidyverse)
library(patchwork)

data("CODrecovery")

par(mfrow = c(3, 1))  
plot(x = CODrecovery$scenario1$time, y = CODrecovery$scenario1$biomass, type = "l", xlab = "Year", ylab = "Abundance", main = "Recovering cod population")
plot(x = CODrecovery$scenario2$time, y = CODrecovery$scenario2$biomass, type = "l", xlab = "Year", ylab = "Abundance", main = "Recovering cod population")
plot(x = CODrecovery$scenario3$time, y = CODrecovery$scenario3$biomass, type = "l", xlab = "Year", ylab = "Abundance", main = "Recovering cod population")
dev.off()


# Idea usando add
plot(x = CODrecovery$scenario1$time, y = CODrecovery$scenario1$biomass, type = "l", xlab = "Year", ylab = "Abundance", main = "Recovering cod population")
lines(x = CODrecovery$scenario2$time, y = CODrecovery$scenario2$biomass, col = "red")
lines(x = CODrecovery$scenario3$time, y = CODrecovery$scenario3$biomass, col = "green")

# Buena
plot(x = CODrecovery$scenario2$time, y = CODrecovery$scenario2$biomass, col = "black",  type = "l")
abline(v = CODrecovery$scenario2$inflection_pt |>  unique(), col = "black", lty = 2)
lines(x = CODrecovery$scenario1$time, y = CODrecovery$scenario1$biomass, col = "red")
lines(x = CODrecovery$scenario3$time, y = CODrecovery$scenario3$biomass, col = "green")
abline(v = CODrecovery$scenario3$inflection_pt |>  unique(), col = "green", lty = 2)


pre_CODrecovery <- subset(CODrecovery$scenario2,time < inflection_pt)
pre_simTransComms <- subset(simTransComms$community1,time < inflection_pt)


####################################
### Ejercicios cortesia de Cesar ###
####################################

greenhouse = read.table(file = "Analisis de series de tiempo en ecologia/ENSC_2025_EWS/end_of_green_house.txt")
dryland = read.table(file = "Analisis de series de tiempo en ecologia/ENSC_2025_EWS/dryland_ecosystem.txt")
desertification = read.table(file = "Analisis de series de tiempo en ecologia/ENSC_2025_EWS/desertification.txt")

greenhouse$time = c(1:nrow(greenhouse))
dryland$time = c(1:nrow(dryland))
desertification$time = c(1:nrow(desertification))

# GreenHouse

greenhouse = greenhouse |> 
  dplyr::select(time,V1) |> 
  dplyr::rename(valores=V1)

greenhouse_rolling = EWSmethods::uniEWS(data = greenhouse,
                   metrics = c("ar1","SD","skew"),
                   method = "rolling",
                   winsize = 50)
plot(greenhouse_rolling,  y_lab = "Density")


greenhouse_expanding = EWSmethods::uniEWS(data = greenhouse,
                               metrics = c("ar1","SD","skew"),
                               method = "expanding", 
                               burn_in = 50,
                               threshold = 2)
plot(greenhouse_expanding,  y_lab = "Density")

### Dryand

dryland = dryland |> 
  dplyr::select(time,V1) |> 
  dplyr::rename(valores = V1)

dryland_rolling = EWSmethods::uniEWS(data = dryland,
                                        metrics = c("ar1","SD","skew"),
                                        method = "rolling",
                                        winsize = 50)
plot(dryland_rolling,  y_lab = "Density")


dryland_expanding = EWSmethods::uniEWS(data = dryland,
                                          metrics = c("ar1","SD", "skew"),
                                          method = "expanding", 
                                          burn_in = 50,
                                          threshold = 2)
plot(dryland_expanding,  y_lab = "Density")




#### desertification

desertification = desertification |> 
  dplyr::select(time,V1) |> 
  dplyr::rename(valores = V1)

desertification_rolling = EWSmethods::uniEWS(data = desertification,
                                     metrics = c("ar1","SD","skew"),
                                     method = "rolling",
                                     winsize = 50)
plot(desertification_rolling,  y_lab = "Density")


desertification_expanding = EWSmethods::uniEWS(data = desertification,
                                       metrics = c("ar1","SD","skew"),
                                       method = "expanding", 
                                       burn_in = 30,
                                       threshold = 2)
plot(desertification_expanding,  y_lab = "Density")

