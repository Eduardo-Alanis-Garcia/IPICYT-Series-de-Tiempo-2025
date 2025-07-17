function y = CaculaStats(u)
featuresTable = table();

% Calculate mean value feature
featuresTable.meanValue = mean(u);

% Calculate median value feature
featuresTable.medianValue = median(u);

% Calculate standard deviation feature
featuresTable.standardDeviation = std(u);

% Calculate mean absolute deviation feature
featuresTable.meanAbsoluteDeviation = mad(u);
% Calculate signal 25th percentile feature
featuresTable.quantile25 = quantile(u,0.25);

% Calculate signal 75th percentile feature
featuresTable.quantile75 = quantile(u,0.75);

% Calculate signal inter quartile range feature
featuresTable.signalIQR = iqr(u);

% Calculate skewness of the signal values
featuresTable.sampleSkewness = skewness(u);

% Calculate kurtosis of the signal values
featuresTable.sampleKurtosis = kurtosis(u);

y = featuresTable;