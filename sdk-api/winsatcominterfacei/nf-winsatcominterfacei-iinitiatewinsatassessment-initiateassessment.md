# IInitiateWinSATAssessment::InitiateAssessment

## Description

[IInitiateWinSATAssessment::InitiateAssessment may be altered or unavailable for releases after Windows 8.1.]

Initiates an ad hoc assessment.

## Parameters

### `cmdLine` [in]

Command-line arguments to pass to WinSAT. The command line cannot be empty. For command line usage, see [WinSAT Command Reference](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2012-R2-and-2012/cc770542(v=ws.11)) on Microsoft TechNet.

### `pCallbacks` [in, optional]

An [IWinSATInitiateEvents](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nn-winsatcominterfacei-iwinsatinitiateevents) interface that you implement to receive notification when the assessment finishes or makes progress. Can be **NULL** if you do not want to receive notifications.

### `callerHwnd` [in, optional]

The window handle of your client. The handle is used to center the WinSAT dialog boxes. If **NULL**, the dialog boxes are centered on the desktop.

## Return value

This method can return one of these values.

This following table lists some of the HRESULT values that this method returns.

| Return code/value | Description |
| --- | --- |
| **S_OK** | WinSAT successfully started. To determine if the assessment ran successfully, implement the [IWinSATInitiateEvents::WinSATComplete](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nf-winsatcominterfacei-iwinsatinitiateevents-winsatcomplete) method and check the value of the *hresult* parameter. |
| **WINSAT_ERROR_COMMAND_LINE_EMPTY**<br><br>0x80040009 | The command line cannot be empty; you must provide command-line arguments. |
| **WINSAT_ERROR_COMMAND_LINE_TOO_LONG**<br><br>0x8004000A | The command line is too long. The maximum length is 30,720 bytes. |
| **WINSAT_ERROR_WINSAT_DOES_NOT_EXIST**<br><br>0x80040011 | Could not find the WinSAT program where expected. |

## Remarks

You typically run an ad hoc assessment to assess one subcomponent of the computer, whereas a formal assessment assesses all subcomponents of the computer. To run a formal assessment, call the [IInitiateWinSATAssessment::InitiateFormalAssessment](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nf-winsatcominterfacei-iinitiatewinsatassessment-initiateformalassessment) method.

Ad hoc assessments are not saved in the WinSAT data store; only formal assessments are saved in the data store (you cannot use the [IQueryRecentWinSATAssessment](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nn-winsatcominterfacei-iqueryrecentwinsatassessment) interface to query the results). To get the results of an ad hoc assessment, include the **–xml***FileName* argument, which will save the results to an XML file that you can later parse.

WinSAT requires administrator privileges to run. If the user does not have administrator privileges, WinSAT will display a dialog box that asks for credentials.

#### Examples

The following example shows how to run an ad hoc assessment and receive notification of its progress.

```cpp
#include <windows.h>
#include <stdio.h>
#include <conio.h>  // For kbhit()
#include <winsatcominterfacei.h>

#pragma comment(lib, "ole32.lib")

BOOL IsKeyEvent(HANDLE hStdIn);

// Class that implements IWinSATInitiateEvents. Implement this class to
// get progress information and completion notification.
class CWinSATCallbacks : public IWinSATInitiateEvents
{
    LONG m_lRefCount;

public:

    // Constructor, Destructor
    CWinSATCallbacks() {m_lRefCount = 1;};
    ~CWinSATCallbacks() {};

    // IUnknown methods
    HRESULT __stdcall QueryInterface(REFIID riid, LPVOID *ppvObj);
    ULONG __stdcall AddRef();
    ULONG __stdcall Release();

    // IWinSATInitiateEvents methods
    HRESULT __stdcall WinSATComplete(HRESULT hr, LPCWSTR description);
    HRESULT __stdcall WinSATUpdate(UINT currentTick, UINT tickTotal, LPCWSTR currentState);
};

HRESULT CWinSATCallbacks::QueryInterface(REFIID riid, LPVOID* ppvObj)
{
    if (riid == __uuidof(IUnknown) || riid == __uuidof(IWinSATInitiateEvents))
    {
        *ppvObj = this;
    }
    else
    {
        *ppvObj = NULL;
        return E_NOINTERFACE;
    }

    AddRef();
    return NOERROR;
}

ULONG CWinSATCallbacks::AddRef()
{
    return InterlockedIncrement(&m_lRefCount);
}

ULONG CWinSATCallbacks::Release()
{
    ULONG  ulCount = InterlockedDecrement(&m_lRefCount);

    if(0 == ulCount)
    {
        delete this;
    }

    return ulCount;
}

// Is called when WinSAT completes the assessment or an error occurs.
HRESULT CWinSATCallbacks::WinSATComplete(HRESULT hr, LPCWSTR description)
{
    if (SUCCEEDED(hr))
    {
        wprintf(L"\n*** %s", description);
    }
    else
    {
        wprintf(L"\n*** The assessment failed with 0x%x (%s)\n", hr, description);
    }

    return S_OK;
}

// There is no progress information for ad hoc assessment. The method provides the
// name of the component being assessed.
HRESULT CWinSATCallbacks::WinSATUpdate(UINT currentTick, UINT tickTotal, LPCWSTR currentState)
{
    return S_OK;
}

void main(void)
{
    HRESULT hr = S_OK;
    IInitiateWinSATAssessment* pAssessment = NULL;
    CWinSATCallbacks* pCallbacks = NULL;  // Class that implements IWinSATInitiateEvents
    LPWSTR pCommand = L"mem -buffersize 32MB -xml .\\MemoryAssessment.xml";
    HANDLE hConsole = INVALID_HANDLE_VALUE;
    DWORD dwWait = 0;

    CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);

    // Get an instance of the assessment interface.
    hr = CoCreateInstance(__uuidof(CInitiateWinSAT),
                          NULL,
                          CLSCTX_INPROC_SERVER,
                          __uuidof(IInitiateWinSATAssessment),
                          (void**)&pAssessment);

    if (FAILED(hr))
    {
        wprintf(L"Failed to create an instance of IInitiateWinSATAssessment. Failed with 0x%x.\n", hr);
        goto cleanup;
    }

    wprintf(L"Running formal assessment... hit any key when complete.\n");

    // Get a handle for console input, so you can break out of the loop.
    hConsole = GetStdHandle(STD_INPUT_HANDLE);
    if (INVALID_HANDLE_VALUE == hConsole)
    {
        wprintf(L"GetStdHandle failed with %lu.\n", GetLastError());
        goto cleanup;
    }

    pCallbacks = new CWinSATCallbacks();
    if (NULL == pCallbacks)
    {
        wprintf(L"Failed to create an instance of the CWinSATCallbacks class.\n");
        goto cleanup;
    }

    // Run the formal assessment.
    hr = pAssessment->InitiateAssessment(pCommand, pCallbacks, NULL);
    if (FAILED(hr))
    {
        // This is a failure to start WinSAT. If WinSAT fails while running,
        // your implementation of the IWinSATInitiateEvents::WinSATComplete
        // method will receive the failure code.
        wprintf(L"InitiateFormalAssessment failed with 0x%x.\n", hr);
        goto cleanup;
    }

    // Loop until the user presses a key or there is an error.
    while (true)
    {
        dwWait = WaitForSingleObject(hConsole, INFINITE);

        if (WAIT_OBJECT_0 == dwWait)  // Console input
        {
            if (IsKeyEvent(hConsole))
                break;
        }
        else if (WAIT_FAILED == dwWait)
        {
            wprintf(L"WaitForSingleObject failed with %lu\n", GetLastError());
            break;
        }
    }

cleanup:

    if (pAssessment)
        pAssessment->Release();

    if (pCallbacks)
        pCallbacks->Release();

    if (hConsole)
        CloseHandle(hConsole);

    CoUninitialize();
}

// Determines whether the console input was a key event.
BOOL IsKeyEvent(HANDLE hStdIn)
{
    INPUT_RECORD Record[128];
    DWORD dwRecordsRead = 0;
    BOOL fKeyPress = FALSE;

    if (ReadConsoleInput(hStdIn, Record, 128, &dwRecordsRead))
    {
        for (DWORD i = 0; i < dwRecordsRead; i++)
        {
            if (KEY_EVENT == Record[i].EventType)
            {
                fKeyPress = TRUE;
                break;
            }
        }
    }

    return fKeyPress;
}

```

## See also

[IInitiateWinSATAssessment](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nn-winsatcominterfacei-iinitiatewinsatassessment)

[IInitiateWinSATAssessment::InitiateFormalAssessment](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nf-winsatcominterfacei-iinitiatewinsatassessment-initiateformalassessment)

[IWinSATInitiateEvents](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nn-winsatcominterfacei-iwinsatinitiateevents)