GPIO_CLIENT_DISCONNECT_IO_PINS GpioClientDisconnectIoPins;

NTSTATUS GpioClientDisconnectIoPins(
  [in] PVOID Context,
  [in] PGPIO_DISCONNECT_IO_PINS_PARAMETERS DisconnectParameters
)
{...}