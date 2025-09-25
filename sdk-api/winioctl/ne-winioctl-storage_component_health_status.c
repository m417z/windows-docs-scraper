typedef enum _STORAGE_COMPONENT_HEALTH_STATUS {
  HealthStatusUnknown = 0,
  HealthStatusNormal,
  HealthStatusThrottled,
  HealthStatusWarning,
  HealthStatusDisabled,
  HealthStatusFailed
} STORAGE_COMPONENT_HEALTH_STATUS, *PSTORAGE_COMPONENT_HEALTH_STATUS;