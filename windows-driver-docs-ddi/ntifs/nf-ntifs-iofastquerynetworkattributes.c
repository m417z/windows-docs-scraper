BOOLEAN IoFastQueryNetworkAttributes(
  POBJECT_ATTRIBUTES             ObjectAttributes,
  ACCESS_MASK                    DesiredAccess,
  ULONG                          OpenOptions,
  PIO_STATUS_BLOCK               IoStatus,
  PFILE_NETWORK_OPEN_INFORMATION Buffer
);