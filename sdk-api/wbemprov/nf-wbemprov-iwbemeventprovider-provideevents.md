# IWbemEventProvider::ProvideEvents

## Description

Windows Management calls the
**IWbemEventProvider::ProvideEvents** method to signal an event provider to begin delivery of its events.

## Parameters

### `pSink` [in]

Pointer to the object sink to which the provider will deliver its events. In an event provider implementation, you should use the
[IWbemObjectSink::Indicate](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-indicate) method to send events through *pSink*. This is in contrast to other providers that may use the
[SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus) method: The
**ProvideEvents** method should use only
**Indicate** to update a sink.

### `lFlags` [in]

Reserved. This parameter must be 0.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

## Remarks

Windows Management calls this method to activate the provider. Windows Management gives an
[IWbemObjectSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemobjectsink) pointer to the event provider. The provider must call the **AddRef** method using this pointer to increment the reference count, and then return from the call.

Typically, the provider will create an independent thread, and deliver the events as they occur to the provided sink interface.

The provider is not permitted to block this call for more than a few seconds, but it must return as quickly as possible to Windows Management.