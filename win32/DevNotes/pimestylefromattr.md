# PIMEStyleFromAttr function

Retrieves styles for a given attribute.

## Parameters

*attr* \[in\]

This parameter can be one of the following values.

**IMESATTR\_FIXEDCONVERTED** (5)

**IMESATTR\_INPUT** (0)

**IMESATTR\_INPUT\_ERROR** (4)

**IMESATTR\_MAX** (5)

**IMESATTR\_MIN** (0)

**IMESATTR\_TARGET\_CONVERTED** (1)

**IMESATTR\_TARGET\_NOTCONVERTED** (4)

## Return value

Returns a pointer to an **IMESTYLE** structure representing the color and non-color settings.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

The **IMESTYLE** structure is defined as follows:

``` syntax
typedef struct {
    union {
        GRFSTY  grfsty;
        struct {
            UINT    fBold:1;
            UINT    fItalic:1;
            UINT    fUl:1;
            UINT    idUl:(sizeof(UINT) * 8 - 3);
        };
    };

    union {
        IMECOLORSTY colorstyText;
        struct {
            UINT    colorIdText;
            union {
                COLORREF    rgbText;
                UINT        colorWinText;
                UINT        colorSpecText;
                UINT        colorFundText;
            };
        };
    };

    union {
        IMECOLORSTY colorstyBack;
        struct {
            UINT    colorIdBack;
            union {
                COLORREF    rgbBack;
                UINT        colorWinBack;
                UINT        colorSpecBack;
                UINT        colorFundBack;
            };
        };
    };

    union {
        IMECOLORSTY colorstyUl;
        struct {
            UINT    colorIdUl;
            union {
                COLORREF    rgbUl;
                UINT        colorWinUl;
                UINT        colorSpecUl;
                UINT        colorFundUl;
            };
        };
    };
} IMESTYLE;
```

## Requirements

| Requirement | Value |
|----------------|-----------------------------------------------------------------------------------------|
| DLL<br> | Imeshare.dll |

