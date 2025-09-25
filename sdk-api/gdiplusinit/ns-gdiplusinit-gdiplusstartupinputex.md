## Description

The **GdiplusStartupInputEx** structure holds a block of arguments that are required by the [GdiplusStartup](https://learn.microsoft.com/windows/win32/api/gdiplusinit/nf-gdiplusinit-gdiplusstartup) function. **GdiplusStartupInputEx** derives from [**GdiplusStartupInput**](https://learn.microsoft.com/windows/win32/api/gdiplusinit/nf-gdiplusinit-gdiplusstartupinput-gdiplusstartupinput).

## Members

### `StartupParameters`

Type: **INT**

See [**GdiplusStartupParams**](https://learn.microsoft.com/windows/win32/api/gdiplusinit/ne-gdiplusinit-gdiplusstartupparams). The default value is **GdiplusStartupDefault** (0).

## Remarks

> ![IMPORTANT]
> For info about operating system (OS) support for the codecs mentioned below, see [Media Feature Pack for Windows 10/11 N (September 2022)](https://support.microsoft.com/windows/media-feature-pack-for-windows-10-11-n-september-2022-78cfeea5-c7d9-4aa8-b38f-ee4df1392009).

The **GdiplusStartupInputEx** structure also defines the following enumeration, which is the type of one of the parameters of the [GdiplusStartupInputEx.GdiplusStartupInputEx(Version,INT,DebugEventProc,BOOL,BOOL)](https://learn.microsoft.com/windows/win32/api/gdiplusinit/nf-gdiplusinit-gdiplusstartupinputex-gdiplusstartupinputex(version_int_debugeventproc_bool_bool).md) constructor.

```cpp
enum class Version : UINT32
{
  V2 = 2,
  V3 = 3 // Enables Heif and Avif image codecs.
         // Unlike other functionalities in Gdiplus,
         // these two codecs require COM to be initialized.
};
```

## See also