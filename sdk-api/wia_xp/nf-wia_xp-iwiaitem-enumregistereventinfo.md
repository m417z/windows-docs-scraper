# IWiaItem::EnumRegisterEventInfo

## Description

The **IWiaItem::EnumRegisterEventInfo** method creates an enumerator used to obtain information about events for which an application is registered.

## Parameters

### `lFlags` [in]

Type: **LONG**

Currently unused. Should be set to zero.

### `pEventGUID` [in]

Type: **const GUID***

Pointer to an identifier that specifies the hardware event for which you want registration information.

### `ppIEnum` [out]

Type: **[IEnumWIA_DEV_CAPS](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-ienumwia_dev_caps)****

Receives the address of a pointer to the [IEnumWIA_DEV_CAPS](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-ienumwia_dev_caps) interface.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

An application invokes this method to create an enumerator object for the event information. **IWiaItem::EnumRegisterEventInfo** stores the address of the [IEnumWIA_DEV_CAPS](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-ienumwia_dev_caps) interface of the enumerator object in the *ppIEnum* parameter. The program then uses the interface pointer to enumerate the properties of the event for which it is registered.

Each [WIA_DEV_CAP](https://learn.microsoft.com/windows/desktop/api/wia_xp/ns-wia_xp-wia_dev_cap) structure includes an indication of whether the event is of type WIA_NOTIFICATION_EVENT or WIA_ACTION_EVENT or both.

Applications must call the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on the interface pointers they receive through the *ppIEnum* parameter.