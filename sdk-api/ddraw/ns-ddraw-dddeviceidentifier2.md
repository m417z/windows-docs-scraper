# DDDEVICEIDENTIFIER2 structure

## Description

The **DDDEVICEIDENTIFIER2** structure is passed to the [IDirectDraw7::GetDeviceIdentifier](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdraw7-getdeviceidentifier) method to obtain information about a device.

## Members

### `szDriver`

Name of the driver.

### `szDescription`

Description of the driver.

### `liDriverVersion`

Version of the driver. It is valid to do less than and greater than comparisons on all 64 bits. Caution should be exercised if you use this element to identify problematic drivers; instead, use the **guidDeviceIdentifier** member for this purpose.

The data takes the following form:

```

wProduct = HIWORD(liDriverVersion.HighPart)
wVersion = LOWORD(liDriverVersion.HighPart)
wSubVersion = HIWORD(liDriverVersion.LowPart)
wBuild = LOWORD(liDriverVersion.LowPart)

```

### `dwDriverVersionLowPart`

### `dwDriverVersionHighPart`

### `dwVendorId`

Identifier of the manufacturer. Can be 0 if unknown.

### `dwDeviceId`

Identifier of the type of chipset. Can be 0 if unknown.

### `dwSubSysId`

Identifier of the subsystem. Typically, this means the particular board. Can be 0 if unknown.

### `dwRevision`

Identifier of the revision level of the chipset. Can be 0 if unknown.

### `guidDeviceIdentifier`

Unique identifier for the driver and chipset pair. Use this value if you want to track changes to the driver or chipset to reprofile the graphics subsystem. It can also be used to identify particular problematic drivers.

### `dwWHQLLevel`

The Windows Hardware Quality Lab (WHQL) certification level for the device and driver pair.

## Remarks

The values in **szDriver** and **szDescription** are for presentation to the user only. They should not be used to identify particular drivers because different strings might be associated with the same device, or the same driver from different vendors might be described differently.

The **dwVendorId**, **dwDeviceId**, **dwSubSysId**, and **dwRevision** members can be used to identify particular chipsets, but use extreme caution.