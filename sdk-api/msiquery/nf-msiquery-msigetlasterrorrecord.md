# MsiGetLastErrorRecord function

## Description

The
**MsiGetLastErrorRecord** function returns the error record that was last returned for the calling process. This function returns a handle that should be closed using
[MsiCloseHandle](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiclosehandle).

## Return value

A handle to the error record. If the last function was successful,
**MsiGetLastErrorRecord** returns a null **MSIHANDLE**.

## Remarks

With the
**MsiGetLastErrorRecord** function, field 1 of the record contains the installer error code. Other fields contain data specific to the particular error. The error record is released internally after this function is run.

If the record is passed to
[MsiProcessMessage](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiprocessmessage), it is formatted by looking up the string in the current database. If there is no installation session but a product database is open, the format string may be obtained by a query on the
[Error table](https://learn.microsoft.com/windows/desktop/Msi/error-table) using the error code, followed by a call to
[MsiFormatRecord](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiformatrecorda). If the error code is known, the parameters may be individually interpreted.

The following functions set the per-process error record or reset it to null if no error occurred. **MsiGetLastErrorRecord** also clears the error record after returning it.

* [MsiOpenDatabase](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiopendatabasea)
* [MsiDatabaseCommit](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msidatabasecommit)
* [MsiDatabaseOpenView](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msidatabaseopenviewa)
* [MsiDatabaseImport](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msidatabaseimporta)
* [MsiDatabaseExport](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msidatabaseexporta)
* [MsiDatabaseMerge](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msidatabasemergea)
* [MsiDatabaseGenerateTransform](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msidatabasegeneratetransforma)
* [MsiDatabaseApplyTransform](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msidatabaseapplytransforma)
* [MsiViewExecute](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiviewexecute)
* [MsiViewModify](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiviewmodify)
* [MsiRecordSetStream](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msirecordsetstreama)
* [MsiGetSummaryInformation](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msigetsummaryinformationa)
* [MsiGetSourcePath](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msigetsourcepatha)
* [MsiGetTargetPath](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msigettargetpatha)
* [MsiSetTargetPath](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msisettargetpatha)
* [MsiGetComponentState](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msigetcomponentstatea)
* [MsiSetComponentState](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msisetcomponentstatea)
* [MsiGetFeatureState](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msigetfeaturestatea)
* [MsiSetFeatureState](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msisetfeaturestatea)
* [MsiGetFeatureCost](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msigetfeaturecosta)
* [MsiGetFeatureValidStates](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msigetfeaturevalidstatesa)
* [MsiSetInstallLevel](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msisetinstalllevel)

Note that it is recommended to use variables of type PMSIHANDLE because the installer closes PMSIHANDLE objects as they go out of scope, whereas you must close MSIHANDLE objects by calling
[MsiCloseHandle](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiclosehandle). For more information see [Use PMSIHANDLE instead of HANDLE](https://learn.microsoft.com/windows/desktop/Msi/windows-installer-best-practices) section in the [Windows Installer Best Practices](https://learn.microsoft.com/windows/desktop/Msi/windows-installer-best-practices).

The following sample uses a call to [MsiDatabaseOpenView](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msidatabaseopenviewa) to show how to obtain extended error information from one of the Windows Installer functions that supports **MsiGetLastErrorRecord**. The example, OpenViewOnDatabase, attempts to open a view on a database handle. The *hDatabase* handle can be
obtained by a call to [MsiOpenDatabase](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiopendatabasea). If opening
the view fails, the function then tries to obtain extended
error information by using **MsiGetLastErrorRecord**.

```cpp
#include <windows.h>
#include <Msiquery.h>
#pragma comment(lib, "msi.lib")
//-------------------------------------------------------------------
// Function: OpenViewOnDatabase
//
// Arguments: hDatabase - handle to a MSI package obtained
//                                        via a call to MsiOpenDatabase
//
// Returns: UINT status code. ERROR_SUCCESS for success.
//--------------------------------------------------------------------------------------------------
UINT __stdcall OpenViewOnDatabase(MSIHANDLE hDatabase)
{
    if (!hDatabase)
        return ERROR_INVALID_PARAMETER;

    PMSIHANDLE hView = 0;
    UINT uiReturn = MsiDatabaseOpenView(hDatabase,
                                TEXT("SELECT * FROM `UnknownTable`"),
                           &hView);

    if (ERROR_SUCCESS != uiReturn)
    {
        // try to obtain extended error information.

        PMSIHANDLE hLastErrorRec = MsiGetLastErrorRecord();

        TCHAR* szExtendedError = NULL;
        DWORD cchExtendedError = 0;
        if (hLastErrorRec)
        {
            // Since we are not currently calling MsiFormatRecord during an
            // install session, hInstall is NULL. If MsiFormatRecord was called
            // via a DLL custom action, the hInstall handle provided to the DLL
            // custom action entry point could be used to further resolve
            // properties that might be contained within the error record.

            // To determine the size of the buffer required for the text,
            // szResultBuf must be provided as an empty string with
            // *pcchResultBuf set to 0.

            UINT uiStatus = MsiFormatRecord(NULL,
                             hLastErrorRec,
                             TEXT(""),
                             &cchExtendedError);

            if (ERROR_MORE_DATA == uiStatus)
            {
                // returned size does not include null terminator.
                cchExtendedError++;

                szExtendedError = new TCHAR[cchExtendedError];
                if (szExtendedError)
                {
                    uiStatus = MsiFormatRecord(NULL,
                                     hLastErrorRec,
                                     szExtendedError,
                                     &cchExtendedError);
                    if (ERROR_SUCCESS == uiStatus)
                    {
                        // We now have an extended error
                        // message to report.

                        // PLACE ADDITIONAL CODE HERE
                        // TO LOG THE ERROR MESSAGE
                        // IN szExtendedError.
                    }

                    delete [] szExtendedError;
                    szExtendedError = NULL;
                }
            }
        }
    }

    return uiReturn;
}

```

## See also

[Installer State Access Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)