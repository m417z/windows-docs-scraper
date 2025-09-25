# _WINBIO_BIR_HEADER structure

## Description

The WINBIO_BIR_HEADER structure contains the Common Biometric Exchange File Format (CBEFF) Patron Format A information that describes the rest of the BIR.

## Members

### `ValidFields`

A Patron Format A bitmask that indicates which CBEFF optional fields are present in the BIR. For more information about all members of WINBIO_BIR_HEADER, follow the link in the Remarks section to the *NISTIR 6529-A Specification*.

### `HeaderVersion`

A structure of type WINBIO_BIR_VERSION that specifies the CBEFF header version.

Versions are represented as 8-bit values of the form: 0x*NM*, where *N* is the major version and *M* is the minor version.

```cpp
typedef UCHAR WINBIO_BIR_VERSION, *PWINBIO_BIR_VERSION;
```

### `PatronHeaderVersion`

A structure of type WINBIO_BIR_VERSION that specifies PATRON_HEADER_VERSION.

### `DataFlags`

A structure of type [WINBIO_BIR_DATA_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ns-winbio_ioctl-_winbio_capture_parameters) that specifies the level of processing expected for a data capture.

### `Type`

A structure of type [WINBIO_BIOMETRIC_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ns-winbio_ioctl-_winbio_sensor_attributes) that specifies the biometric type.

### `Subtype`

A structure of type [WINBIO_BIOMETRIC_SENSOR_SUBTYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ns-winbio_ioctl-_winbio_sensor_attributes) that specifies the biometric subtype.

### `Purpose`

A structure of type [WINBIO_BIR_PURPOSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ns-winbio_ioctl-_winbio_capture_parameters) that specifies the intended use of the data.

### `DataQuality`

A structure of type WINBIO_BIR_QUALITY that specifies the biometric data quality. Quality measurements are represented as signed integers in the range 0-100, except:

-1 Quality measurements are supported by the BIR creator, but no value is set in the BIR.

-2 Quality measurements are not supported by the BIR creator.

```cpp
typedef CHAR WINBIO_BIR_QUALITY, *PWINBIO_BIR_QUALITY;
```

### `CreationDate`

Specifies the creation date and time of this BIR in UTC by using the format YYYYMMDDhhmmss.

### `ValidityPeriod`

Specifies the validity period of this BIR by using the format described in *CreationDate*.

### `ValidityPeriod.BeginDate`

### `ValidityPeriod.EndDate`

### `BiometricDataFormat`

A structure of type [WINBIO_REGISTERED_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_types/ns-winbio_types-_winbio_registered_format) that specifies the data format of the **StandardDataBlock** for this [WINBIO_BIR](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_types/ns-winbio_types-_winbio_bir).

### `ProductId`

A structure of type [WINBIO_REGISTERED_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_types/ns-winbio_types-_winbio_registered_format) that specifies the product identifier for the component that generated the **StandardDataBlock** for this WINBIO_BIR.

## Remarks

You can find more information about the fields of the standard biometric header in the [NISTIR 6529-A Specification](https://csrc.nist.gov/publications/detail/nistir/6529/a/final).

## See also

[WINBIO_BIR](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_types/ns-winbio_types-_winbio_bir)

[WINBIO_BIR_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_types/ns-winbio_types-_winbio_bir_data)