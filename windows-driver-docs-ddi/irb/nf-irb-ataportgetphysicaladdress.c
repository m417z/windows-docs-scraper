IDE_PHYSICAL_ADDRESS AtaPortGetPhysicalAddress(
  [in]            PVOID              ChannelExtension,
  [in, optional]  PIDE_REQUEST_BLOCK Irb,
  [in, optional]  PVOID              VirtualAddress,
  [out, optional] ULONG              *Length
);