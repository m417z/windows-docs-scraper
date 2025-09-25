typedef enum  {
  PowerActionNone           = 0,
  PowerActionReserved       = ( PowerActionNone + 1 ),
  PowerActionSleep          = ( PowerActionReserved + 1 ),
  PowerActionHibernate      = ( PowerActionSleep + 1 ),
  PowerActionShutdown       = ( PowerActionHibernate + 1 ),
  PowerActionShutdownReset  = ( PowerActionShutdown + 1 ),
  PowerActionShutdownOff    = ( PowerActionShutdownReset + 1 ),
  PowerActionWarmEject      = ( PowerActionShutdownOff + 1 )
} POWER_ACTION, *PPOWER_ACTION;