# IStreamBufferConfigure::SetDirectory

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **SetDirectory** method sets the directory where backing files are saved.

## Parameters

### `pszDirectoryName` [in]

Pointer to a null-terminated string containing the fully qualified directory name. If the specified directory does not exist, it will be created.

## Return value

Returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_UNEXPECTED** | The [StreamBufferConfig](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/streambufferconfig-object) object was not initialized. |
| **S_OK** | The method succeeded. |

## Remarks

Before calling this method, call [IStreamBufferInitialize::SetHKEY](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-istreambufferinitialize-sethkey) to specify a registry key where the information will be stored.

The specified directory is used to store backing files. If no directory is specified, the files are saved in a hidden system directory inside the Temp directory. This directory is not used to store files created by [Recording](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/recording-object) objects; those files are stored in a directory specified by the [IStreamBufferSink::CreateRecorder](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-istreambuffersink-createrecorder) method.

Backing files are created as hidden sytem files.

## See also

[IStreamBufferConfigure Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambufferconfigure)