typedef enum _IO_SESSION_STATE {
  IoSessionStateCreated,
  IoSessionStateInitialized,
  IoSessionStateConnected,
  IoSessionStateDisconnected,
  IoSessionStateDisconnectedLoggedOn,
  IoSessionStateLoggedOn,
  IoSessionStateLoggedOff,
  IoSessionStateTerminated,
  IoSessionStateMax
} IO_SESSION_STATE, *PIO_SESSION_STATE;