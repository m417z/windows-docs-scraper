## Description

The *pHalQuerySystemInformation* callback function reads the MCA banks' status registers.

## Parameters

### `InformationClass` [in]

The HalMcaLogInformation to read the current MCA error log. If any of the uncorrected Machine Check errors is found, it is returned in the buffer. For Itanium systems, specify HalCmcLogInformation to read the current corrected CPU error log and HalCpeLogInformation to read the current corrected platform error log.

### `BufferSize` [in]

The size, in bytes, of the buffer that the caller supplies.

### `Buffer` [out]

A pointer to a caller-supplied buffer of type MCA_EXCEPTION that will contain the information returned by this routine. For Intel Itanium processors, the returned information must be compliant, at a minimum, with the V3.0 SAL specification, Error Record Structures, January 2001, Appendix B"". For Intel Pentium Pro processors, the information is as described in the following code example.

```cpp
typedef union _MCI_STATS {
  struct {
    USHORT  McaCod;
    USHORT  MsCod;
    ULONG  OtherInfo   : 25;
    ULONG  Damage    : 1;
    ULONG  AddressValid  : 1;
    ULONG  MiscValid  : 1;
    ULONG  Enabled    : 1;
    ULONG  UnCorrected  : 1;
    ULONG  OverFlow  : 1;
    ULONG  Valid    : 1;
  } MciStats;

  ULONGLONG  QuadPart;
} MCI_STATS, *PMCI_STATS;

typedef union _MCI_ADDR{
  struct {
    ULONG Address;
    ULONG Reserved;
  } MciAddr;

  ULONGLONG  QuadPart;
} MCI_ADDR, *PMCI_ADDR;

typedef struct _MCA_EXCEPTION {

  ULONG  VersionNumber;  // Version number of this record type
  MCA_EXCEPTION_TYPE  ExceptionType;  // MCA or MCE
  LARGE_INTEGER  TimeStamp;  // exception recording timestamp
  ULONG  ProcessorNumber;// processor number

  union {
    struct {
      UCHAR  BankNumber;  // bank number
      MCI_STATS  Status;
      MCI_ADDR  Address;
      ULONGLONG  Misc;
    } Mca;

    struct {
      ULONGLONG  McAddress;  // physical address for the cycle causing the error
      ULONGLONG  McType;   // cycle specification causing the error
    } Mce;
  } u;

} MCA_EXCEPTION, *PMCA_EXCEPTION;
```

### `ReturnedLength` [out]

The number of bytes that are returned in Buffer.

## Return value

Returns STATUS_SUCCESS if an error log exists.

## Remarks

The **HalQuerySystemInformation** function returns the first error. It is the MCA driver's responsibility to call this routine again to see if there are any more errors available.
>Windows Vista and later versions of Windows do not support the type of Machine Check Architecture (MCA) and Machine Check Exception (MCE) reporting that is described in this topic. MCA and MCE reporting are supported through [Windows Hardware Error Architecture (WHEA)](https://learn.microsoft.com/windows-hardware/drivers/whea) instead.

## See also