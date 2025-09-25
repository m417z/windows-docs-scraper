# IGPEInformation::PolicyChanged

## Description

The **PolicyChanged** method informs the
Group Policy Object Editor that policy settings have changed.

## Parameters

### `bMachine` [in]

Specifies whether computer or user policy has changed. If this value is **TRUE**,
computer policy has changed. If this value is **FALSE**, user policy has changed.

### `bAdd` [in]

Specifies whether this is an add or delete operation. If this parameter is **FALSE**,
the last policy setting for the specified extension *pGuidExtension* is removed. In all
other cases, this parameter is **TRUE**.

### `pGuidExtension` [in]

Pointer to the **GUID** or unique name of the snap-in extension that will process
policy. If the GPO is to be processed by the snap-in that processes .pol files, this parameter must specify the
**REGISTRY_EXTENSION_GUID** value.

### `pGuidSnapin` [in]

Pointer to the GUID or unique name of the snap-in extension making this method call.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the method returns one of the COM error codes
defined in the Platform SDK header file WinError.h.

## Remarks

An extension must call this method every time it makes a change to a group policy object. Note that when you
write an MMC snap-in you must implement the [IComponentData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponentdata)
interface and call the [IComponentData::Notify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponentdata-notify)
method. To get the [IGPEInformation](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nn-gpedit-igpeinformation) interface, set the
*event* parameter of the
**IComponentData::Notify** method to be
**MMCN_EXPAND** and the *arg* parameter to
**TRUE**. You can then obtain the
**IGPEInformation** interface by calling
**QueryInterface** and by using the usual Rules for Implementing QueryInterface.

For example, you can obtain the interface by calling as follows.

```cpp
lpDataObject->QueryInterface(IID_IGPEInformation, (LPVOID lpDataObject->*)&m_pGPTInformation);
```

## See also

[Group Policy Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-interfaces)

[Group Policy Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[IGPEInformation](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nn-gpedit-igpeinformation)