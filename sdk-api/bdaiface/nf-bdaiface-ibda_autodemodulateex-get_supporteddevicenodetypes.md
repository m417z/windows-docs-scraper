# IBDA_AutoDemodulateEx::get_SupportedDeviceNodeTypes

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_SupportedDeviceNodeTypes** method retrieves a list of the device node types that the demodulator supports.

## Parameters

### `ulcDeviceNodeTypesMax` [in]

Specifies the size of the *pguidDeviceNodeTypes* array.

### `pulcDeviceNodeTypes` [out]

If *pguidDeviceNodeTypes* is **NULL**, receives the number of device node types that the demodulator supports. If *pguidDeviceNodeTypes* is not **NULL**, receives the number of node types that were copied into the *pguidDeviceNodeTypes* array.

### `pguidDeviceNodeTypes` [in, out]

Pointer to an array of GUIDs, or **NULL**.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

If *pguidDeviceNodeTypes* is **NULL**, the method returns the number of supported node types in the *pulcDeviceNodeTypes* parameter. Otherwise, the method copies the node types into the *pguidDeviceNodeTypes* array, up to a maximum of *ulcDeviceNodeTypesMax*.

## See also

[IBDA_AutoDemodulateEx Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_autodemodulateex)