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
| **S\_OK**<br>0 (0x0) | The function was successful.<br> |
| **S\_FALSE**<br>1 (0x1) | Enabled is **FALSE** and the volume was not already in raw access mode.<br> |
| **E\_ACCESSDENIED**<br>2147942405 (0x80070005) | The volume cannot be locked.<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Fveapi.dll |

