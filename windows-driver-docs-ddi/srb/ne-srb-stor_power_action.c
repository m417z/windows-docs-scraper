typedef enum {
  StorPowerActionNone,
  StorPowerActionReserved,
  StorPowerActionSleep,
  StorPowerActionHibernate,
  StorPowerActionShutdown,
  StorPowerActionShutdownReset,
  StorPowerActionShutdownOff,
  StorPowerActionWarmEject
} STOR_POWER_ACTION, *PSTOR_POWER_ACTION;