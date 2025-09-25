## Description

Requests the delivery of notifications regarding changes to particular dynamic keyword address ([FW_DYNAMIC_KEYWORD_ADDRESS0](https://learn.microsoft.com/windows/win32/api/netfw/ns-netfw-fw_dynamic_keyword_address0)) objects. Based on the flag passed in, notifications can be raised for only a subset of the addresses.

For more info, and code examples, see [Firewall dynamic keywords](https://learn.microsoft.com/windows/win32/ics/firewall-dynamic-keywords).

## Parameters

### `flags`

Type: \_In\_ **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The following flags are defined in `fwpmu.h`.

**FWPM_NOTIFY_ADDRESSES_AUTO_RESOLVE** indicates that notifications will be delivered only for objects that have the [FW_DYNAMIC_KEYWORD_ADDRESS_FLAGS_AUTO_RESOLVE](https://learn.microsoft.com/windows/win32/api/netfw/ne-netfw-fw_dynamic_keyword_address_flags) flag set.

**FWPM_NOTIFY_ADDRESSES_NON_AUTO_RESOLVE** indicates that notifications will be delivered only for objects that *don't* have the [FW_DYNAMIC_KEYWORD_ADDRESS_FLAGS_AUTO_RESOLVE](https://learn.microsoft.com/windows/win32/api/netfw/ne-netfw-fw_dynamic_keyword_address_flags) flag set.

**FWPM_NOTIFY_ADDRESSES_AUTO_RESOLVE** indicates that notifications will be delivered for *all* dynamic keyword address objects.

### `callback`

Type: \_In\_ **[FWPM_DYNAMIC_KEYWORD_CALLBACK0](https://learn.microsoft.com/windows/win32/api/fwpmu/nc-fwpmu-fwpm_dynamic_keyword_callback0)**

A pointer to a callback function that you implement, which will be invoked when a notification is ready for delivery.

### `context`

Type: \_In\_opt\_ **void\***

An optional context pointer. This pointer is passed to the callback function.

### `subscriptionHandle`

Type: \_Out\_ **[HANDLE](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

The address of a handle, which is populated with a handle to the newly created subscription.

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

If the function succeeds, then it returns **ERROR_SUCCESS**. Otherwise, it returns one of the following values.

|Return value|Description|
|-|-|
|ERROR_INVALID_PARAMETER|The *flags* value is zero.|

## Remarks

Notifications for *AutoResolve* dynamic keyword addresses are delivered when an object is added or deleted.

Notifications for *non-AutoResolve* dynamic keyword addresses are delivered when an object is added, deleted, or updated.

No data is provided to the callback function. You can use the **Enumeration** API if you need information about what has changed on the system.

You're responsible for closing the handle when you no longer need subscription. You must do so by calling the [FwpmDynamicKeywordUnsubscribe0](https://learn.microsoft.com/windows/win32/api/fwpmu/nf-fwpmu-fwpmdynamickeywordunsubscribe0) function.

Your implementation of [FWPM_DYNAMIC_KEYWORD_CALLBACK0](https://learn.microsoft.com/windows/win32/api/fwpmu/nc-fwpmu-fwpm_dynamic_keyword_callback0) should react to changes in dynamic keyword address objects quickly, because it is scheduled on a ThreadPool thread, and could affect other wait operations.

## See also

* [Firewall dynamic keywords](https://learn.microsoft.com/windows/win32/ics/firewall-dynamic-keywords)
* [FW_DYNAMIC_KEYWORD_ADDRESS0](https://learn.microsoft.com/windows/win32/api/netfw/ns-netfw-fw_dynamic_keyword_address0)
* [FW_DYNAMIC_KEYWORD_ADDRESS_FLAGS](https://learn.microsoft.com/windows/win32/api/netfw/ne-netfw-fw_dynamic_keyword_address_flags)