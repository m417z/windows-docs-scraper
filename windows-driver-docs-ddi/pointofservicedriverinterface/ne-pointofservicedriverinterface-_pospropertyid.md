## Description

This enumeration defines the property identifiers for the properties that device drivers need to handle to be considered a barcode scanner or a magnetic strip reader (MSR).

## Constants

### `IsEnabled`

Indicates whether the device is enabled. An enabled device is expected to be powered on and fully functional. In a disabled state, the device is not expected to generate input and can be powered down. (Read/Write).

### `IsDisabledOnDataReceived`

Indicates whether to disable the device after each scan event. This allows the hardware to enter an idle power-saving mode as frequently as possible. (Read/Write).

### `PowerState`

Reports the current power state of the device.

### `BarcodeScannerIsDecodeDataEnabled`

When set to **TRUE**, the driver must return decoded bar code data in the form of **ScanDataLabel** in addition to **ScanData** when raising a data received event. Decoded barcode data typically only contains data from the scanner with header information, scanner generated symbol character, and length identification removed. (Read/Write).

### `BarcodeScannerCapabilities`

Contains information about what functionality the barcode scanner supports. For example, a barcode scanner may support imaging and standard power reporting but not statistics updating and reporting. For more information about the values for barcode capabilities, see [PosBarcodeScannerCapabilitiesType](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ns-pointofservicedriverinterface-_posbarcodescannercapabilitiestype). (Read-only).

### `BarcodeScannerSupportedSymbologies`

Contains an array representing the complete list of symbologies that the barcode scanner is capable of reading. Also returns the number of bytes required for the array of symbologies. For symbology definitions, see [BarcodeSymbology](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicecommontypes/ne-pointofservicecommontypes-_barcodesymbology). (Read-only).

### `BarcodeScannerActiveSymbologies`

Indicates the symbologies that the barcode scanner is actively handling. (Write-only). For symbology definitions, see [BarcodeSymbology](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicecommontypes/ne-pointofservicecommontypes-_barcodesymbology).

### `BarcodeScannerSupportedProfiles`

Returns the list of supported driver-defined device configuration profiles. (Read-only).

### `BarcodeScannerActiveProfile`

Sets the active device configuration profile. Configure the driver using one of the driver- or manufacturer-defined profiles in the list returned by the **BarcodeScannerSupportedProfiles** property. (Write-Only). For example, you may have one profile for warehouse staff and another profile for the sales department. Each profile is expected to configure the device based on the driver or manufacturer definition.

### `MagneticStripeReaderIsDecodeDataEnabled`

Indicates whether to provide raw or decoded data from the most recently swiped card. If decoded data is provided to the application, set to **true**; otherwise, set to **false**. (Read/write).

### `MagneticStripeReaderCapabilities`

Returns a [PosMagneticStripeReaderCapabilitiesType](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ns-pointofservicedriverinterface-_posmagneticstripereadercapabilitiestype) that describes the capabilities of the MSR. (Read-Only).

### `MagneticStripeReaderSupportedCardTypes`

Returns an array of [MsrCardType](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ne-pointofservicedriverinterface-_msrcardtype)s supported by the MSR. (Read-only).

### `MagneticStripeReaderDeviceAuthenticationProtocol`

The driver must return a [MsrAuthenticationProtocolType](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/dn772165(v=vs.85)) that describes the device authentication protocol supported by the MSR. (Read-only).

### `MagneticStripeReaderErrorReportingType`

Specifies the level of error reporting that the MSR supports. For more information about the values for error reporting levels, see [MsrErrorReportingType](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ne-pointofservicedriverinterface-_msrerrorreportingtype). (Read/write).

### `MagneticStripeReaderTracksToRead`

Specifies which tracks the application will receive following a card swipe. Does not indicate the capability of the device hardware; instead, it is an application-configurable property representing the tracks to be read. For more information about track values, see [MsrTrackIds](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ne-pointofservicedriverinterface-_msrtrackids). (Read/write).

### `MagneticStripeReaderIsTransmitSentinelsEnabled`

Indicates whether the track data contains start and end sentinel values. (Read/write).

### `MagneticStripeReaderIsDeviceAuthenticated`

Indicates whether the device is authenticated. (Read-only).

### `MagneticStripeReaderDataEncryptionAlgorithm`

Specifies the [MsrDataEncryption](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ne-pointofservicedriverinterface-_msrdataencryption) that will be used to encrypt the track data. (Read/write).

### `BarcodeScannerVideoDeviceId`

Defines the **BarcodeScannerVideoDeviceId** constant.

## See also

[IOCTL_POINT_OF_SERVICE_GET_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ni-pointofservicedriverinterface-ioctl_point_of_service_get_property)

[IOCTL_POINT_OF_SERVICE_SET_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ni-pointofservicedriverinterface-ioctl_point_of_service_set_property)