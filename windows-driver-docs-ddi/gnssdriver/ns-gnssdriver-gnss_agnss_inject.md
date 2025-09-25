## Description

The **GNSS_AGNSS_INJECT** structure defines the parameters for AGNSS injection.

## Members

### `Size`

Structure size.

### `Version`

Version number.

### `InjectionType`

Indicates the specific type of AGNSS injection.

Depending on the type, the driver must access the specific data element of the structure. For example, if the type is GNSS_AGNSS_PositionInjection, use the Position element.

### `InjectionStatus`

Indicates whether any error was encountered in gathering the needed injection data.

The driver must ignore the injection if this field does not indicate success.

### `InjectionDataSize`

Size of the injection data.

### `Unused`

Padding buffer reserved for future use.

### `Time`

[GNSS_AGNSS_INJECTTIME](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_agnss_injecttime) contains the format for AGNSS time injection.

### `Position`

[GNSS_AGNSS_INJECTPOSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_agnss_injectposition) contains the format for AGNSS position injection.

### `BlobData`

[GNSS_AGNSS_INJECTBLOB](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_agnss_injectblob) contains the format for AGNSS extended ephemeris injection.