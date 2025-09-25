# _PosMagneticStripeReaderCapabilitiesType structure

## Description

This structure defines the kinds of magnetic stripe reader (MSR) capabilities that a device supports, such as whether the device supports track data masking.

## Members

### `PowerReportingType`

Indicates the type of power reporting that is supported by the device.

### `IsStatisticsReportingSupported`

Indicates whether the device supports [IOCTL_POINT_OF_SERVICE_RETRIEVE_STATISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ni-pointofservicedriverinterface-ioctl_point_of_service_retrieve_statistics).

### `IsStatisticsUpdatingSupported`

Indicates whether the device supports [IOCTL_POINT_OF_SERVICE_UPDATE_STATISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ni-pointofservicedriverinterface-ioctl_point_of_service_update_statistics).

### `CardAuthenticationLength`

The length, in bytes, of the name of the type of authentication that the device uses.

### `SupportedEncryptionAlgorithms`

The supported encryption algorithm. See [MsrDataEncryption](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ne-pointofservicedriverinterface-_msrdataencryption).

### `AuthenticationLevel`

The authentication level that the device supports.

### `IsIsoSupported`

Indicates whether the device supports ISO cards.

### `IsJisOneSupported`

Indicates whether device supports JIS Type-I cards.

### `IsJisTwoSupported`

Indicates whether device supports JIS Type-II cards.

### `IsTrackDataMaskingSupported`

Indicates whether the device is capable of masking track data.

### `IsTransmitSentinelsSupported`

Indicates whether the devices is able to transmit start and end sentinels.