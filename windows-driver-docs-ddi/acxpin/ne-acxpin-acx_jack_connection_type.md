## Description

The **ACX_JACK_CONNECTION_TYPE** enumeration is used by the [ACX_JACK_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_jack_description) structure to describe the type of a physical connection jack.

## Constants

### `AcxConnTypeUnknown`

Indicates that the connection type is unknown.

### `AcxConnType3Point5mm`

Indicates that the connection type is a 3.5 millimeter jack.

### `AcxConnTypeQuarter`

Indicates that the connection type is a quarter-inch jack.

### `AcxConnTypeAtapiInternal`

Indicates that the connection type is an ATAPI internal connector.

### `AcxConnTypeRCA`

Indicates that the connection type is an RCA jack.

### `AcxConnTypeOptical`

Indicates that the connection type is an optical audio jack.

### `AcxConnTypeOtherDigital`

Indicates that the connection type is some other type of digital audio jack not specifically defined by this enum.

### `AcxConnTypeOtherAnalog`

Indicates that the connection type is some other type of analog audio jack not specifically defined by this enum.

### `AcxConnTypeMultichannelAnalogDIN`

Indicates that the connection type is a multichannel analog DIN connector.

### `AcxConnTypeXlrProfessional`

Indicates that the connection type is an XLR jack.

### `AcxConnTypeRJ11Modem`

Indicates that the connection type is an RJ11 modem jack.

### `AcxConnTypeCombination`

Indicates that the connection type is a combination jack.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)