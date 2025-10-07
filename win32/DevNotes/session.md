# SESSION structure

\[This structure contains information required only when using the **DeleteExtractedFiles** and **Extract** functions, which are not supported. This documentation is provided for informational purposes only.\]

The **SESSION** structure contains information about the current session.

## Members

**act**

The action to perform. This member can be one of the values from the following enumerated type.

``` syntax
typedef enum {
    actBAD,         // Invalid action
    actHELP,        // Show help
    actDEFAULT,     // Perform default action based on command line arguments
    actDIRECTORY,   // Force display of cabinet directory
    actEXTRACT,     // Force file extraction
    actCOPY,        // Do single file-to-file copy
} ACTION;
```

**hflist**

The handle to a list of files specified on the command line. This datatype is declared as follows:

`typedef void *HFILELIST;`

**fAllCabinets**

A flag that indicates whether more than one cabinet file should be processed. If this value is **TRUE**, continuation cabinets are processed.

**fOverwrite**

A flag that indicates whether existing files should be overwritten. If this value is **TRUE**, existing files are overwritten.

**fNoLineFeed**

A flag that indicates whether the last `printf` call has the newline (`\n`) characters. If this value is **TRUE**, the last `printf` call did not include the newline characters.

**fSelfExtract**

A flag that indicates whether a cabinet is self extracting. If this value is **TRUE**, the cabinet is self extracting.

**cbSelfExtractSize**

The length of the executable (.exe) portion of a self-extracting cabinet.

**cbSelfExtractSize**

The length of the CAB portion of a self-extracting cabinet.

**ahfSelf**

The file handles to the cabinet.

`#define cMAX_CAB_FILE_OPEN 2 `

**cErrors**

The count of errors encountered during the extraction session.

**hfdi**

A handle to the FDI context. This datatype is declared as follows:

`typedef void FAR *HFDI; `

**erf**

The FDI error structure. See [**ERF**](https://learn.microsoft.com/windows/win32/api/fdi_fci_types/ns-fdi_fci_types-erf).

**cFiles**

The count of files processed.

**cbTotalBytes**

The total number of bytes extracted.

**perr**

The pass through FDI.

**se**

The spill file error. This member can be one of the values from the following enumerated type.

``` syntax
typedef enum {
    seNONE,                     // No error
    seNOT_ENOUGH_MEMORY,        // Not enough RAM
    seCANNOT_CREATE,            // Cannot create spill file
    seNOT_ENOUGH_SPACE,         // Not enough space for spill file
} SPILLERR;
```

**cbSpill**

The size of the spill file requested.

**achSelf**

The name of the executable (.exe) file.

`#define cbFILE_NAME_MAX 256`

**achMsg**

The message formatting buffer.

`#define cbMAX_LINE 256`

**achLine**

The line formatting buffer.

**achLocation**

The output directory.

**achFile**

The current file name being extracted.

**achDest**

The forced destination file name.

**achCabPath**

The path to look at for a cabinet file.

**fContinuationCabinet**

A flag that indicates whether the current cabinet is the first one processed. If set to **TRUE**, it is not the first cabinet processed.

**fShowReserveInfo**

A flag that indicates whether reserve information should be provided. If set to **TRUE**, the information is made available.

**fNextCabCalled**

This member provides a way to determine which of the **acab** entries to use if we are processing all files in a cabinet set (**fAllCabinet** is set to **TRUE**).

**acab**

The last two entries in the cabinet set. This structure is defined as follows:

``` syntax
typedef struct {
    char    achCabPath[cbFILE_NAME_MAX];     // Cabinet file path
    char    achCabFilename[cbFILE_NAME_MAX]; // Cabinet file name.ext
    char    achDiskName[cbFILE_NAME_MAX];    // User readable disk label
    USHORT  setID;
    USHORT  iCabinet;
} CABINET;
typedef CABINET *PCABINET;
```

**achZap**

The prefix to strip from the file name.

`#define cbFILE_NAME_MAX 256`

**achCabinetFile**

The current cabinet file.

`#define cbFILE_NAME_MAX 256`

**cArgv**

The default self-extracting argc.

**pArgv**

A pointer to a pointer to the default self-extracting argv\[\].

**fDestructive**

A flag that minimizes the disk space needed when set to **TRUE**.

**iCurrentFolder**

If **fDestructive** is set to **TRUE**, extract only the current folder.

## See also

[**DeleteExtractedFiles**](https://learn.microsoft.com/windows/win32/devnotes/deleteextractedfiles)

[**Extract**](https://learn.microsoft.com/windows/win32/devnotes/extract)

