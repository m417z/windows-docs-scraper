typedef struct _VPOSVERSIONINFO {
  IN ULONG   Size;
  OUT ULONG  MajorVersion;
  OUT ULONG  MinorVersion;
  OUT ULONG  BuildNumber;
  OUT USHORT ServicePackMajor;
  OUT USHORT ServicePackMinor;
} VPOSVERSIONINFO, *PVPOSVERSIONINFO;