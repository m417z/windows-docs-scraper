# IVssComponentEx::GetPrepareForBackupFailureMsg

## Description

Returns the [PrepareForBackup](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-p) failure message string that a writer has set for a given component.

Both writers and requesters can call this method.

## Parameters

### `pbstrFailureMsg` [out]

A pointer to a null-terminated wide character string containing the failure message that describes an error that occurred
while processing a [PrepareForBackup](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-p)
event.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The failure message was successfully obtained. |
| **S_FALSE** | No [PrepareForBackup](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-p) failure message was set for the component. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |

## Remarks

The caller is responsible for freeing the string that the *pbstrFailureMsg* parameter points to by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

#### Examples

```cpp
#include <windows.h>
#include "vss.h"
#include "vsmgmt.h"

#define CHKARG_ASSERT(EXPR)
do
{
    if(! ( EXPR ) )
    {
        assert(FALSE);
        hr = E_INVALIDARG;
        goto exit;
    }
}
while ( FALSE, FALSE );

#define  CHK(HR)
do
{
    hr =  ( HR ) ;
    if(FAILED(HR))
    {
        hr = HR;
        goto exit;
    }
}
while ( FALSE, FALSE );

STDMETHODIMP CheckAsrBackupErrorMsg
(
      IVssBackupComponents           *pBackup,
      const WCHAR              *pwszWriterName
)
{
    CComPtr<IVssWriterComponentsExt> spWriter;
    CComPtr<IVssComponent>   spComponent;
    CComPtr<IVssComponentEx> spComponentEx;
    UINT    cWriterComponents = 0;
    UINT    iWriterComponent = 0;
    UINT    cComponents = 0;
    UINT    iComponent = 0;
    VSS_ID  idWriter;
    VSS_ID  idInstance;
    CComBSTR bstrFailureMsg;
    HRESULT  hr = S_OK;
    CHKARG_ASSERT( pBackup );
    CHKARG_ASSERT( pwszWriterName );

    CHK( pBackup->GetWriterComponentsCount( &cWriterComponents ) );

    for( iWriterComponent = 0; iWriterComponent < cWriterComponents; iWriterComponent++ )
    {
        spWriter.Release();
        CHK( pBackup->GetWriterComponents( iWriterComponent, &spWriter ) );
        CHK( spWriter->GetWriterInfo(&idInstance, &idWriter) );
        if( idWriter != c_ASRWriterId )
        {
            continue;
        }

        CHK( spWriter->GetComponentCount(&cComponents) );
        for( iComponent = 0; iComponent < cComponents; iComponent++ )
        {
            spComponent.Release();
            spComponentEx.Release();
            CHK( spWriter->GetComponent(iComponent, &spComponent) );
            CHK( spComponent->QueryInterface(__uuidof(IVssComponentEx), (void**)&spComponentEx) );

            bstrFailureMsg.Empty();
            CHK( spComponentEx->GetPrepareForBackupFailureMsg(&bstrFailureMsg) );

            if( ::SysStringLen(bstrFailureMsg) != 0 )
            {
                //  Write into the event log.
                Log_SPP_ERROR_WRITER( &ft, __LINE__, pwszWriterName, bstrFailureMsg );

                //  The ASR writer writes the same message to all components.
                //  Log the message once.
                break;
            }
        }
    }

exit:
    return hr;
}

```

## See also

[CVssWriter::OnPrepareBackup](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpreparebackup)

[IVssComponentEx](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponentex)

[IVssComponentEx::SetPrepareForBackupFailureMsg](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponentex-setprepareforbackupfailuremsg)