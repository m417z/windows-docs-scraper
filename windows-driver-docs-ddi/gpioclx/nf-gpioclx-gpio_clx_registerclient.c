NTSTATUS GPIO_CLX_RegisterClient(
  [in]      WDFDRIVER                        Driver,
  [in, out] PGPIO_CLIENT_REGISTRATION_PACKET RegistrationPacket,
  [in]      PUNICODE_STRING                  RegistryPath
);