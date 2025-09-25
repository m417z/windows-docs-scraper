## Description

The **AcxTargetPinGetWdfIoTarget** given an existing ACXTARGETPIN object, returns its corresponding WDFIOTARGET object. For more information about WDF IO targets see [Initializing a General I/O Target](https://learn.microsoft.com/windows-hardware/drivers/wdf/initializing-a-general-i-o-target).

## Parameters

### `TargetPin`

An existing ACXTARGETPIN object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Return value

Returns the WDFIOTARGET object associated with the target pin target.

## Remarks

### Example

```cpp

    _In_ ACXTARGETPIN PinTarget;

...

    WDFIOTARGET ioTarget;

    ioTarget = AcxTargetPinGetWdfIoTarget(PinTarget);

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxtargets.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxtargets/)