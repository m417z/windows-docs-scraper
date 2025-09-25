# WAB_PARAM structure

## Description

Do not use. Contains the input information to pass to [WABOpen](https://learn.microsoft.com/previous-versions/windows/desktop/api/wabapi/nc-wabapi-wabopen).

## Members

### `cbSize`

Type: **ULONG**

Value of type **ULONG** that specifies the size of the **WAB_PARAM** structure in bytes.

### `hwnd`

Type: **HWND**

Value of type **HWND** that specifies the window handle of the calling client application. Can be **NULL**.

### `szFileName`

Type: **LPTSTR**

Value of type **LPTSTR** that specifies the WAB file name to open. If this parameter is **NULL**, the default Address Book file is opened.

### `ulFlags`

Type: **ULONG**

Value of type **ULONG** that specifies flags that control the behavior of WAB functionality. Available only on Internet Explorer 4.0 or later.

#### WAB_USE_OE_SENDMAIL (WAB_USE_OE_SENDMAIL)

Indicates that WAB is to use Outlook Express for e-mail before checking for a default Simple MAPI client. Default behavior is to check for the Simple MAPI client first.

#### WAB_ENABLE_PROFILES (WAB_ENABLE_PROFILES)

Invokes WAB in an Identity-aware session using Identity-Manager based profiles. Available only on Internet Explorer 5 or later.

### `guidPSExt`

Type: **GUID**

Value of type **GUID** that specifies the GUID that identifies the calling application's property sheet extensions. The GUID can be used to determine whether the extension property sheets are displayed or not. Available only on Internet Explorer 5 or later.