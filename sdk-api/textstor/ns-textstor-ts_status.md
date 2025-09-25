# TS_STATUS structure

## Description

The **TS_STATUS** structure contains document status data.

## Members

### `dwDynamicFlags`

Contains a set of flags that can be changed by an app at run time. For example, an app can enable a check box for the user to reset the document status. This member can contain zero, or one or more of the following values.

| Value | Meaning |
|-----------------|----------------------------|
| TS_SD_LOADING | The document is loading. |
| TS_SD_READONLY | The document is read-only. |

### `dwStaticFlags`

Contains a set of flags that cannot be changed at run time. This member can contain zero, or one or more of the following values.

| Value | Meaning |
|-------------------------------|------------------------------------------------------------------------------------------|
| TS_SS_DISJOINTSEL | The document supports multiple selections. |
| TS_SS_REGIONS | The document can contain multiple regions. |
| TS_SS_TRANSITORY | The document is expected to have a short usage cycle. |
| TS_SS_NOHIDDENTEXT | The document will never contain hidden text. |
| TS_SS_TKBAUTOCORRECTENABLE | **Starting with Windows 8:** The document supports autocorrection provided by the touch keyboard. |
| TS_SS_TKBPREDICTIONENABLE | **Starting with Windows 8:** The document supports text suggestions provided by the touch keyboard. |

## Remarks

The [TF_STATUS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms629192(v=vs.85)) structure contains document status data.

[TF_STATUS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms629192(v=vs.85)) is an alias for **TS_STATUS**.

**dwDynamicFlags** contains a set of flags that can be changed by an app at run time. For example, an app can enable a check box for the user to reset the status of documentation. This member can contain zero, or one or more of the following values.

| Value | Meaning |
|----------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| TF_SD_LOADING | The document is loading. |
| TF_SD_READONLY | The document is read-only. |
| TS_SD_INPUTPANEMANUALDISPLAYENABLE | The system does not attempt automatic touch keyboard invocation when the control is touched. Instead, the app calls [TryShow(CoreInputViewKind)](https://learn.microsoft.com/uwp/api/windows.ui.viewmanagement.core.coreinputview.tryshow) to show the keyboard when appropriate (the app should monitor input to select the [CoreInputViewKind](https://learn.microsoft.com/uwp/api/windows.ui.viewmanagement.core.coreinputviewkind)). |
| TS_SD_UIINTEGRATIONENABLE | **Starting with Windows 8.1:** The text control owning the document sets this flag to indicate its support of Input Method Editor (IME) UI integration. When specified, the IME should attempt to align the candidate window below the text box instead of floating near the cursor.<br>**Note:** Not all IMEs respond to this flag. IME candidate lists are positioned on the screen with sufficient size to allow basic text input. In some cases, the IME may enforce a reasonable minimum size. An IME might also choose to adjust the candidate window and keyboard input behavior to provide a better user experience, such as using a horizontal candidate list and allowing some keys such as up arrow and down arrow to be sent to the app for scenarios such as suggestion list navigation. |
| TF_SD_TKBAUTOCORRECTENABLE | **Starting with Windows 8.1:** The document supports autocorrection provided by the touch keyboard. This support can change during the lifetime of the control. |
| TF_SD_TKBPREDICTIONENABLE | **Starting with Windows 8.1:** The document supports text suggestions provided by the touch keyboard. This support can change during the lifetime of the control. |

**dwStaticFlags** contains a set of flags that cannot be changed at run time. This member can contain zero, or one or more of the following values.

| Value | Meaning |
|-------------------------------|------------------------------------------------------------------------------------------|
| TF_SS_DISJOINTSEL | The document supports multiple selections. |
| TF_SS_REGIONS | The document can contain multiple regions. |
| TF_SS_TRANSITORY | The document is expected to have a short usage cycle. |
| TF_SS_TKBAUTOCORRECTENABLE | **Starting with Windows 8:** The document supports autocorrection provided by the touch keyboard. |
| TF_SS_TKBPREDICTIONENABLE | **Starting with Windows 8:** The document supports text suggestions provided by the touch keyboard. |

## See also

[ITextStoreACP::GetStatus](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-getstatus)

[ITextStoreACPSink::OnStatusChange](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacpsink-onstatuschange)

[ITextStoreAnchor::GetStatus](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-getstatus)

[ITextStoreAnchorSink::OnStatusChange](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchorsink-onstatuschange)