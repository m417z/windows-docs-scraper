# FveEnableRawAccessW function

Enables or disables reading and writing of disk sectors.

## Parameters

*VolumeName* \[in\]

A unique identifier for the disk volume.

*Enabled* \[in\]

If **TRUE**, allows access to the raw volume. If **FALSE**, no access is allowed to the raw volume. If raw access has already been enabled but this value is **FALSE**, the volume is remounted and revalidated.

## Return value

This function returns one of the following codes or another error code if it fails.

| Return code/value | Description |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------|
| **S\_OK**

0 (0x0) | The function was successful.\ | | **S\_FALSE**

1 (0x1) | Enabled is **FALSE** and the volume was not already in raw access mode.\ | | **E\_ACCESSDENIED**

2147942405 (0x80070005) | The volume cannot be locked.\ | ## Requirements | Requirement | Value | |-------------------------------------|---------------------------------------------------------------------------------------| | Minimum supported client\ | Windows Vista \[desktop apps only\]\ | | Minimum supported server\ | Windows Server 2008 \[desktop apps only\]\ | | DLL\ | Fveapi.dll |