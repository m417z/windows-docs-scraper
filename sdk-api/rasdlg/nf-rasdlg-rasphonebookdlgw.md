# RasPhonebookDlgW function

## Description

The
**RasPhonebookDlg** function displays the main **Dial-Up Networking** dialog box. From this modal dialog box, the user can dial, edit, or delete a selected phone-book entry, create a new phone-book entry, or specify user preferences. The
**RasPhonebookDlg** function returns when the dialog box closes.

## Parameters

### `lpszPhonebook` [in]

Pointer to a **null**-terminated string that specifies the full path and file name of a phone-book (PBK) file. If this parameter is **NULL**, the function uses the current default phone-book file. The default phone-book file is the one selected by the user in the **User Preferences** property sheet of the **Dial-Up Networking** dialog box.

### `lpszEntry` [in]

Pointer to a **null**-terminated string that specifies the name of the phone-book entry to highlight initially. If this parameter is **NULL**, or if the specified entry does not exist, the dialog box highlights the first entry in the alphabetic list.

### `lpInfo` [in, out]

Pointer to the
[RASPBDLG](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377607(v=vs.85)) structure that specifies additional input and output parameters.

On input, the **dwSize** member of this structure must specify the sizeof(
[RASPBDLG](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377607(v=vs.85))).

If an error occurs, the **dwError** member of the structure receives, on output, an error code; otherwise, it receives zero.

## Return value

If the user selects the **Connect** button and the function establishes a connection, the return value is **TRUE**. Otherwise, the function returns **FALSE**.

 If an error occurs, the **dwError** member of the
[RASPBDLG](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377607(v=vs.85)) structure returns a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

The following sample code brings up the **Dial-Up Networking** dialog. The dialog displays dialing information for the first entry from the default phonebook file.

```cpp
#include <windows.h>
#include <stdio.h>
#include "ras.h"
#include "rasdlg.h"
#pragma comment(lib, "rasapi32.lib")

int main (){

    // Initialize the return code
    BOOL nRet = TRUE;

    // Allocate heap memory for the RASPBLDG structure
    RASPBDLG * lpInfo = (LPRASPBDLG)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(RASPBDLG));

    // The dwsize member of lpInfo must contain the structure size, or the
    // call to RasPhonebookDlg will fail
    lpInfo->dwSize = sizeof(RASPBDLG);

    // Open a user dialog box
    nRet = RasPhonebookDlg(NULL,NULL,lpInfo);

    if(nRet == TRUE){
        // The user dialed a connection successfully
        printf("User pressed Connect\n");
    }else{
        if(lpInfo->dwError != 0){
            printf("RasPhonebookDlg failed: Error = %d\n", lpInfo->dwError);
        }else{
            // The user closed the dialog box manually
            printf("User pressed Close\n");
        }
    }

    // Free the heap memory for the RASPBLDG structure
    HeapFree(GetProcessHeap(), 0, lpInfo);
    return 0;
}

```

## See also

[RASPBDLG](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377607(v=vs.85))

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)

## Remarks

> [!NOTE]
> The rasdlg.h header defines RasPhonebookDlg as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).