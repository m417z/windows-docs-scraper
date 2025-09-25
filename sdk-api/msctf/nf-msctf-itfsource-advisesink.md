# ITfSource::AdviseSink

## Description

Installs an advise sink.

## Parameters

### `riid` [in]

Identifies the type of advise sink to install.

This parameter can be one of the following values when the **ITfSource** object is obtained from an [ITfThreadMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfthreadmgr) object.

This parameter can be one of the following values when the [ITfSource](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfsource) object is obtained from an [ITfContext](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontext) object.

| Value | Meaning |
| --- | --- |
| **IID_ITfActiveLanguageProfileNotifySink** | Installs an [ITfActiveLanguageProfileNotifySink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfactivelanguageprofilenotifysink) advise sink. |
| **IID_ITfDisplayAttributeNotifySink** | Installs an [ITfDisplayAttributeNotifySink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfdisplayattributenotifysink) advise sink. |
| **IID_ITfKeyTraceEventSink** | Installs an [ITfKeyTraceEventSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfkeytraceeventsink) advise sink. |
| **IID_ITfPreservedKeyNotifySink** | Installs an [ITfPreservedKeyNotifySink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfpreservedkeynotifysink) advise sink. |
| **IID_ITfThreadFocusSink** | Installs an [ITfThreadFocusSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfthreadfocussink) advise sink. |
| **IID_ITfThreadMgrEventSink** | Installs an [ITfThreadMgrEventSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfthreadmgreventsink) advise sink. |

### `punk` [in]

The advise sink **IUnknown** pointer.

### `pdwCookie` [out]

Address of a DWORD value that receives an identifying cookie. This value is used to uninstall the advise sink in a subsequent call to [ITfSource::UnadviseSink](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfsource-unadvisesink). Receives (DWORD)-1 if a failure occurs.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **CONNECT_E_CANNOTCONNECT** | The advise sink cannot be installed. |
| **CONNECT_E_ADVISELIMIT** | The maximum number of advise sinks has been reached. |
| **E_FAIL** | An unspecified error occurred. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |

## See also

[ITfActiveLanguageProfileNotifySink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfactivelanguageprofilenotifysink)

[ITfCompartment](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcompartment)

[ITfCompartmentEventSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcompartmenteventsink)

[ITfContext](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontext)

[ITfContextKeyEventSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontextkeyeventsink)

[ITfDisplayAttributeNotifySink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfdisplayattributenotifysink)

ITfEditTransactionSink

[ITfInputProcessorProfiles](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfinputprocessorprofiles)

[ITfKeyTraceEventSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfkeytraceeventsink)

[ITfLangBarItem](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritem)

[ITfLangBarItemSink](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritemsink)

[ITfLanguageProfileNotifySink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itflanguageprofilenotifysink)

[ITfPreservedKeyNotifySink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfpreservedkeynotifysink)

[ITfSource](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfsource)

[ITfSource::UnadviseSink](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfsource-unadvisesink)

[ITfStatusSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfstatussink)

[ITfSystemLangBarItemSink](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itfsystemlangbaritemsink)

[ITfTextEditSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itftexteditsink)

[ITfTextLayoutSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itftextlayoutsink)

[ITfThreadFocusSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfthreadfocussink)

[ITfThreadMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfthreadmgr)

[ITfThreadMgrEventSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfthreadmgreventsink)