# OPM_CONFIGURE_PARAMETERS structure

## Description

Contains an [Output Protection Manager](https://learn.microsoft.com/windows/desktop/medfound/output-protection-manager) (OPM) or Certified Output Protection Manager (COPP) command.

## Members

### `omac`

An [OPM_MAC](https://learn.microsoft.com/windows/desktop/api/ksopmapi/ns-ksopmapi-opm_omac) structure. Fill in this structure with the Message Authentication Code (MAC) of the command data. Use AES-based one-key CBC MAC (OMAC) to calculate this value.

### `guidSetting`

A GUID that specifies the command. For more information, see [OPM Commands](https://learn.microsoft.com/windows/desktop/medfound/opm-commands).

### `ulSequenceNumber`

A command sequence number. The application must keep a running count of the commands issued. For each command, increment the sequence number by one.

On the first call to [IOPMVideoOutput::Configure](https://learn.microsoft.com/windows/desktop/api/opmapi/nf-opmapi-iopmvideooutput-configure), set **ulSequenceNumber** equal to the starting command sequence number, which is specified when the application calls [IOPMVideoOutput::FinishInitialization](https://learn.microsoft.com/windows/desktop/api/opmapi/nf-opmapi-iopmvideooutput-startinitialization). On each subsequent call, increment **ulSequenceNumber** by 1.

Exception: If the [IOPMVideoOutput::Configure](https://learn.microsoft.com/windows/desktop/api/opmapi/nf-opmapi-iopmvideooutput-configure) method fails, do not increment the sequence number. Instead, re-use the same number for the next command.

### `cbParametersSize`

The number of bytes of valid data in the **abParameters** member.

### `abParameters`

The data for the command. The meaning of the data depends on the command. For more information, see [OPM Commands](https://learn.microsoft.com/windows/desktop/medfound/opm-commands).

## Remarks

The layout of this structure is identical to the [AMCOPPCommand](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-amcoppcommand) structure used in Certified Output Protection Protocol (COPP).

Initialize this structure as follows.

1. Fill in all the structure members except the **omac** member.
2. Use the OMAC 1 algorithm to calculate a message authentication code (MAC) for the block of data that appears after the **omac** member (excluding the **omac** member).
3. Copy the MAC to the **omac** member.

## See also

[IOPMVideoOutput::Configure](https://learn.microsoft.com/windows/desktop/api/opmapi/nf-opmapi-iopmvideooutput-configure)

[OPM Structures](https://learn.microsoft.com/windows/desktop/medfound/opm-structures)

[Output Protection Manager](https://learn.microsoft.com/windows/desktop/medfound/output-protection-manager)