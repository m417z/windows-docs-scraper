# IActivationFactory::ActivateInstance

## Description

Creates a new instance of the Windows Runtime class that is associated with the current activation factory.

## Parameters

### `instance` [out]

Type: **[IInspectable](https://learn.microsoft.com/windows/desktop/api/inspectable/nn-inspectable-iinspectable)****

A pointer to a new instance of the class that is associated with the current activation factory.

## Return value

Type: **HRESULT**

This function can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The new class instance was created successfully. |
| **E_INVALIDARG** | *instance* is **NULL**. |
| **E_NOINTERFACE** | The [IInspectable](https://learn.microsoft.com/windows/desktop/api/inspectable/nn-inspectable-iinspectable) interface is not implemented by the class that is associated with the current activation factory. |
| **E_OUTOFMEMORY** | Failed to create an instance of the class. |

## Remarks

Use the **ActivateInstance** function to activate a Windows Runtime class. The **ActivateInstance** function connects to the activation factory that is associated with the specified activatable class identifier, creates an instance by calling the zero-argument constructor on the class, and releases the activation factory.

## See also

[IActivationFactory](https://learn.microsoft.com/windows/desktop/api/activation/nn-activation-iactivationfactory)

[RoActivateInstance](https://learn.microsoft.com/windows/desktop/api/roapi/nf-roapi-roactivateinstance)