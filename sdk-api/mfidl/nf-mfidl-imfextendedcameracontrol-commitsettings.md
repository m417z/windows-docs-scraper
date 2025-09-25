## Description

Commits the configured control settings to the camera driver.

## Return value

Returns S_OK on success.

## Remarks

The following example demonstrates setting the [KSCAMERA_EXTENDEDPROP_VIDEOTORCH_ON](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-cameracontrol-extended-torchmode) flag and committing the setting.

```cpp
if (FAILED(m_cameraController->GetExtendedCameraControl(MF_CAPTURE_ENGINE_MEDIASOURCE,
    KSPROPERTY_CAMERACONTROL_EXTENDED_TORCHMODE,
    cameraControl.put())))
{
    // Return false to indicate that the Torch Mode control is not available.
    return false;
}

ULONGLONG capabilities = cameraControl->GetCapabilities();

// Check if the torch can be turned on.
if (capabilities & KSCAMERA_EXTENDEDPROP_VIDEOTORCH_ON)
{
    // Check if the torch is off.
    if ((cameraControl->GetFlags() & KSCAMERA_EXTENDEDPROP_VIDEOTORCH_ON) == 0)
    {
        // Torch is off. Tell the camera to turn it on.
        check_hresult(cameraControl->SetFlags(KSCAMERA_EXTENDEDPROP_VIDEOTORCH_ON));
        // Write the changed settings to the driver.
        check_hresult(cameraControl->CommitSettings());
    }
}

```

## See also