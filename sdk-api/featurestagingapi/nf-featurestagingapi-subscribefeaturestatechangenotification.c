void SubscribeFeatureStateChangeNotification(
  [out]          FEATURE_STATE_CHANGE_SUBSCRIPTION *subscription,
  [in]           PFEATURE_STATE_CHANGE_CALLBACK    callback,
  [in, optional] void                              *context
);