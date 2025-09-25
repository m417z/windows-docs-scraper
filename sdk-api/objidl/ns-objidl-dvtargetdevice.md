# DVTARGETDEVICE structure

## Description

Specifies information about the target device for which data is being composed. **DVTARGETDEVICE** contains enough information about a Windows target device so a handle to a device context (**HDC**) can be created using the [CreateDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdca) function.

## Members

### `tdSize`

The size, in bytes, of the **DVTARGETDEVICE** structure. The initial size is included so the structure can be copied more easily.

### `tdDriverNameOffset`

The offset, in bytes, from the beginning of the structure to the device driver name, which is stored as a NULL-terminated string in the **tdData** buffer.

### `tdDeviceNameOffset`

The offset, in bytes, from the beginning of the structure to the device name, which is stored as a NULL-terminated string in the **tdData** buffer. This value can be zero to indicate no device name.

### `tdPortNameOffset`

The offset, in bytes, from the beginning of the structure to the port name, which is stored as a NULL-terminated string in the **tdData** buffer. This value can be zero to indicate no port name.

### `tdExtDevmodeOffset`

The offset, in bytes, from the beginning of the structure to the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure retrieved by calling [DocumentProperties](https://learn.microsoft.com/windows/desktop/printdocs/documentproperties).

### `tdData`

An array of bytes containing data for the target device. It is not necessary to include empty strings in **tdData** (for names where the offset value is zero).

## Remarks

Some OLE 1 client applications incorrectly construct target devices by allocating too few bytes in the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure for the **DVTARGETDEVICE**. They typically only supply the number of bytes in the **dmSize** member of **DEVMODE**. The number of bytes to be allocated should be the sum of **dmSize** + **dmDriverExtra**. When a call is made to the [CreateDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdca) function with an incorrect target device, the printer driver tries to access the additional bytes and unpredictable results can occur. To help protect against a crash and make the additional bytes available, OLE pads the size of OLE 2 target devices created from OLE 1 target devices.

## See also

[FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc)

[IEnumFORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumformatetc)

[IViewObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iviewobject)

[OleConvertOLESTREAMToIStorage](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleconvertolestreamtoistorage)