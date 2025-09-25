# MBN_BAND_CLASS enumeration

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The **MBN_BAND_CLASS** enumerated type defines the frequency band classes.

## Constants

### `MBN_BAND_CLASS_NONE:0`

Unknown band class.

### `MBN_BAND_CLASS_0:0x1`

Band class 0.

### `MBN_BAND_CLASS_I:0x2`

Band class 1.

### `MBN_BAND_CLASS_II:0x4`

Band class 2.

### `MBN_BAND_CLASS_III:0x8`

Band class 3.

### `MBN_BAND_CLASS_IV:0x10`

Band class 4.

### `MBN_BAND_CLASS_V:0x20`

Band class 5.

### `MBN_BAND_CLASS_VI:0x40`

Band class 6.

### `MBN_BAND_CLASS_VII:0x80`

Band class 7.

### `MBN_BAND_CLASS_VIII:0x100`

Band class 8.

### `MBN_BAND_CLASS_IX:0x200`

Band class 9.

### `MBN_BAND_CLASS_X:0x400`

Band class 10.

### `MBN_BAND_CLASS_XI:0x800`

Band class 11.

### `MBN_BAND_CLASS_XII:0x1000`

Band class 12.

### `MBN_BAND_CLASS_XIII:0x2000`

Band class 13.

### `MBN_BAND_CLASS_XIV:0x4000`

Band class 14.

### `MBN_BAND_CLASS_XV:0x8000`

Band class 15.

### `MBN_BAND_CLASS_XVI:0x10000`

Band class 16.

### `MBN_BAND_CLASS_XVII:0x20000`

Band class 17.

### `MBN_BAND_CLASS_CUSTOM:0x80000000`

Custom band class.

## Remarks

These values are used by the **gsmBandClass** and **cdmaBandClass** members of the [MBN_INTERFACE_CAPS](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_interface_caps) structure. The meanings are dependent upon which member is using them and are detailed in the structure documentation