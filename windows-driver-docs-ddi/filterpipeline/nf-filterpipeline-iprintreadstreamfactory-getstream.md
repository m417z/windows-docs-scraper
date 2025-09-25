# IPrintReadStreamFactory::GetStream

## Description

The `GetStream` method gets the stream interface.

## Parameters

### `ppStream` [out]

A pointer to an [IPrintReadStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-iprintreadstream) interface. The filter can use this interface to read the contents of the print ticket.

## Return value

`GetStream` returns an **HRESULT** value.

## Remarks

The following code example shows how a filter can use **IPrintReadStreamFactory** to access the per-user print ticket.

```cpp
VARIANT var;
VariantInit(&var);

HRESULT hr = pIPropertyBag->GetProperty(
  XPS_FP_USER_PRINT_TICKET,
  &var);

if (SUCCEEDED(hr))
{
 IPrintReadStreamFactory   *pPrintReadStreamFactory;

 hr = V_UNKNOWN(&var)->QueryInterface(
 IID_IPrintReadStreamFactory,
 reinterpret_cast<void **>(&pPrintReadStreamFactory));

 if (SUCCEEDED(hr))
    {
 IPrintReadStream *pPrintTicketStream;

 hr = pPrintReadStreamFactory->GetStream(&pPrintTicketStream);

 if (SUCCEEDED(hr))
      {

       // Use the print ticket here.
       // It's OK to cache the pointer
       // to use now and release later.

 pPrintTicketStream->Release();
      }

 pPrintReadStreamFactory->Release();
    }

 VariantClear(&var);
}
```