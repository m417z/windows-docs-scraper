typedef struct _GET_UNIT_IDS {
  OUT LARGE_INTEGER UniqueID;
  OUT ULONG         VendorID;
  OUT ULONG         ModelID;
  OUT ULONG         ulVendorLength;
  OUT PWSTR         VendorText;
  OUT ULONG         ulModelLength;
  OUT PWSTR         ModelText;
  OUT ULONG         UnitModelID;
  OUT ULONG         ulUnitModelLength;
  OUT PWSTR         UnitModelText;
} GET_UNIT_IDS, *PGET_UNIT_IDS;