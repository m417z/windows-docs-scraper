# IMbnInterface::GetSubscriberInformation

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets the subscriber information.

## Parameters

### `subscriberInformation` [out, retval]

A pointer to the address of an [IMbnSubscriberInformation](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsubscriberinformation) interface that contains subscriber information for the device. If this method returns any value other than **S_OK**, this parameter is **NULL**.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. *subscriberInformation* contains a valid interface. |
| **E_PENDING** | The information is not available. The Mobile Broadband service is currently probing for the information. The calling application can get notified when the information is available by registering for the [OnSubscriberInformationChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterfaceevents-onsubscriberinformationchange) method of [IMbnInterfaceEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterfaceevents). |

## Remarks

The **GetSubscriberInformation** method returns the subscriber-related information, including subscriber ID, SIM international circuit card number, and phone numbers associated with this interface.

When this method is called from a Windows Store app with mobile operator privileges it will only return the SIM International circuit card number defined by the [SimIccID](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnsubscriberinformation-get_simiccid) property.

Some of the values returned in subscriber information are populated only when the ready state which as reported by the [GetReadyState](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterface-getreadystate) method of [IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface) is **MBN_READY_STATE_INITIALIZED**. Whenever there is a change in the subscriber information associated with the Mobile Broadband device, the Mobile Broadband service will notify registered applications by calling the [OnSubscriberInformationChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterfaceevents-onsubscriberinformationchange) method of [IMbnInterfaceEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterfaceevents).

Subscriber information for a device will not change once the device ready state is **MBN_READY_STATE_INITIALIZED**.

## See also

[IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface)