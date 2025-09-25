typedef enum _UCSI_POWER_DIRECTION_ROLE {
  UcsiPowerDirectionRoleProvider = 0x1,
  UcsiPowerDirectionRoleConsumer = 0x2,
  UcsiPowerDirectionRoleAcceptSwap = 0x4,
  UcsiPowerDirectionRoleProviderAcceptSwap = 0x5,
  UcsiPowerDirectionRoleConsumerAcceptSwap = 0x6
} UCSI_POWER_DIRECTION_ROLE;