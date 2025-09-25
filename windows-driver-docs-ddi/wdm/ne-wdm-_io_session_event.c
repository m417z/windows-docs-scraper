typedef enum _IO_SESSION_EVENT {
  IoSessionEventIgnore,
  IoSessionEventCreated,
  IoSessionEventTerminated,
  IoSessionEventConnected,
  IoSessionEventDisconnected,
  IoSessionEventLogon,
  IoSessionEventLogoff,
  IoSessionEventMax
} IO_SESSION_EVENT, *PIO_SESSION_EVENT;