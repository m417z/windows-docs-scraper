# IPart::GetControlInterface

## Description

The **GetControlInterface** method gets a reference to the specified control interface, if this part supports it.

## Parameters

### `nIndex` [in]

The control interface number. If a part supports *n* control interfaces, the control interfaces are numbered from 0 to *n*– 1.

### `ppInterfaceDesc` [out]

Pointer to a pointer variable into which the method writes the address of the [IControlInterface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-icontrolinterface) interface of the specified audio function. Through this method, the caller obtains a counted reference to the interface. The caller is responsible for releasing the interface, when it is no longer needed, by calling the interface's **Release** method. If the **GetControlInterface** call fails, **ppFunction* is **NULL**.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer *ppFunction* is **NULL**. |
| **E_INVALIDARG** | Parameter *nIndex* is out of range. |
| **E_NOTFOUND** | The part does not have a control interface. |

## See also

[IControlInterface Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-icontrolinterface)

[IPart Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-ipart)