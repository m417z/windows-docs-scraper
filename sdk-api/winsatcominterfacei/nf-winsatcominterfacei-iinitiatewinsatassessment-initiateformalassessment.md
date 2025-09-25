# IInitiateWinSATAssessment::InitiateFormalAssessment

## Description

[IInitiateWinSATAssessment::InitiateFormalAssessment may be altered or unavailable for releases after Windows 8.1.]

Initiates a formal assessment.

## Parameters

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
| **WINSAT_ERROR_WINSAT_DOES_NOT_EXIST**<br><br>0x80040011 | Could not find the WinSAT program where expected. |

## Remarks

You typically run a formal assessment to assess all subcomponents of the computer, whereas an ad hoc assessment assesses one subcomponent of the computer. To run an ad hoc assessment, call the [IInitiateWinSATAssessment::InitiateAssessment](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nf-winsatcominterfacei-iinitiatewinsatassessment-initiateassessment) method.

To get the results of a formal assessment, use the [IQueryRecentWinSATAssessment](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nn-winsatcominterfacei-iqueryrecentwinsatassessment) interface.

If you call this function from a Windows application, implement the [IWinSATInitiateEvents](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nn-winsatcominterfacei-iwinsatinitiateevents) interface so that you can display progress information and receive notification when the assessment is complete. For a Windows console application, showing progress is not necessary because WinSAT writes progress information to the console window.

Note that WinSAT requires administrator privileges to run. If the user does not have administrator privileges, WinSAT will display a dialog box that asks for credentials.

#### Examples

The following example shows how to run a formal assessment and receive notification of its progress.

```cpp
#include <windows.h>
#include <stdio.h>
#include <conio.h>  // For kbhit()
#include <winsatcominterfacei.h>

#pragma comment(lib, "ole32.lib")

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

// Is called when the assessment makes progress. Indicates the percentage of the assessment
// that is complete and the current component being assessed.
HRESULT CWinSATCallbacks::WinSATUpdate(UINT currentTick, UINT tickTotal, LPCWSTR currentState)
{
    // Typically, you would provide the tick values to a ProgressBar control.

    if (tickTotal > 0)
    {
        wprintf(L"\n*** Percent complete: %u%%\n", 100*currentTick/tickTotal);
        wprintf(L"*** Currently assessing: %s\n\n", currentState);
    }

    return S_OK;
}

void main(void)
{
    HRESULT hr = S_OK;
    IInitiateWinSATAssessment* pAssessment = NULL;
    CWinSATCallbacks* pCallbacks = NULL;  // Class that implements IWinSATInitiateEvents

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

    pCallbacks = new CWinSATCallbacks();
    if (NULL == pCallbacks)
    {
        wprintf(L"Failed to create an instance of the CWinSATCallbacks class.\n");
        goto cleanup;
    }

    // Run the formal assessment.
    hr = pAssessment->InitiateFormalAssessment(pCallbacks, NULL);
    if (FAILED(hr))
    {
        // This is a failure to start WinSAT. If WinSAT fails while running,
        // your implementation of the IWinSATInitiateEvents::WinSATComplete
        // method will receive the failure code.
        wprintf(L"InitiateFormalAssessment failed with 0x%x.\n", hr);
        goto cleanup;
    }

    while (!_kbhit())
        Sleep(10);

cleanup:

    if (pAssessment)
        pAssessment->Release();

    if (pCallbacks)
        pCallbacks->Release();

    CoUninitialize();
}

```

## See also

[IInitiateWinSATAssessment](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nn-winsatcominterfacei-iinitiatewinsatassessment)

[IInitiateWinSATAssessment::InitiateAssessment](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nf-winsatcominterfacei-iinitiatewinsatassessment-initiateassessment)

[IQueryRecentWinSATAssessment](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nn-winsatcominterfacei-iqueryrecentwinsatassessment)