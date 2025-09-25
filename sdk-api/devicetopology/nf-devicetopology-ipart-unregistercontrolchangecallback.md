# IPart::UnregisterControlChangeCallback

## Description

The **UnregisterControlChangeCallback** method removes the registration of an [IControlChangeNotify](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-icontrolchangenotify) interface that the client previously registered by a call to the [IPart::RegisterControlChangeCallback](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-ipart-registercontrolchangecallback) method.

## Parameters

### `pNotify` [in]

Pointer to the **IControlChangeNotify** interface whose registration is to be deleted. The client passed this same interface pointer to the part object in a previous call to the **IPart::RegisterControlChangeCallback** method. If the **UnregisterControlChangeCallback** method succeeds, it calls the **Release** method on the client's **IControlChangeNotify** interface.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Pointer *pNotify* is **NULL**. |
| **E_NOTFOUND** | Interface instance **pNotify* is not currently registered. |

## Remarks

Before the client releases its final reference to the **IControlChangeNotify** interface, it should call **UnregisterControlChangeCallback** to unregister the interface. Otherwise, the application leaks the resources held by the **IControlChangeNotify** and **IPart** objects. Note that the **IPart::RegisterControlChangeCallback** method calls the client's **IControlChangeNotify::AddRef** method, and **UnregisterControlChangeCallback** calls the **IControlChangeNotify::Release** method. If the client errs by releasing its reference to the **IControlChangeNotify** interface before calling **UnregisterControlChangeCallback**, the **IPart** object never releases its reference to the **IControlChangeNotify** interface. For example, a poorly designed **IControlChangeNotify** implementation might call **UnregisterControlChangeCallback** from the destructor for the **IControlChangeNotify** object. In this case, the client will not call **UnregisterControlChangeCallback** until the **IPart** object releases its reference to the **IControlChangeNotify** interface, and the **IPart** object will not release its reference to the **IControlChangeNotify** interface until the client calls **UnregisterControlChangeCallback**. For more information about the **AddRef** and **Release** methods, see the discussion of the **IUnknown** interface in the Windows SDK documentation.

## See also

[IControlChangeNotify Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-icontrolchangenotify)

[IPart Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-ipart)

[IPart::RegisterControlChangeCallback](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-ipart-registercontrolchangecallback)