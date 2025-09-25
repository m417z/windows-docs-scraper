# RoActivateInstance function

## Description

Activates the specified Windows Runtime class.

## Parameters

### `activatableClassId` [in]

Type: **[HSTRING](https://learn.microsoft.com/windows/desktop/WinRT/hstring)**

The class identifier that is associated with the activatable runtime class.

### `instance` [out]

Type: **[IInspectable](https://learn.microsoft.com/windows/desktop/api/inspectable/nn-inspectable-iinspectable)****

A pointer to the activated instance of the runtime class.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The class was activated successfully. |
| **E_POINTER** | *instance* is **NULL**. |
| **CO_E_NOTINITIALIZED** | The thread has not been initialized in the Windows Runtime by calling the [RoInitialize](https://learn.microsoft.com/windows/desktop/api/roapi/nf-roapi-roinitialize) function. |
| **E_ACCESSDENIED** | The [TrustLevel](https://learn.microsoft.com/windows/desktop/api/inspectable/ne-inspectable-trustlevel) for the class requires a full-trust process. |
| **E_NOINTERFACE** | The [IInspectable](https://learn.microsoft.com/windows/desktop/api/inspectable/nn-inspectable-iinspectable) interface is not implemented by the specified class. |
| **E_OUTOFMEMORY** | Failed to create an instance of the class. |

## Remarks

Use the **RoActivateInstance** function to activate a Windows Runtime class. The **RoActivateInstance** function connects to the activation factory that is associated with the specified activatable class identifier, creates an instance by calling the zero-argument constructor on the class, and releases the activation factory.

## See also

[CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance)

[IActivationFactory](https://learn.microsoft.com/windows/desktop/api/activation/nn-activation-iactivationfactory)

[IInspectable](https://learn.microsoft.com/windows/desktop/api/inspectable/nn-inspectable-iinspectable)

[TrustLevel](https://learn.microsoft.com/windows/desktop/api/inspectable/ne-inspectable-trustlevel)