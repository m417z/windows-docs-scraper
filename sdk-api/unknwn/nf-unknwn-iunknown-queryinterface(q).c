template<class Q>
HRESULT
STDMETHODCALLTYPE
QueryInterface(_COM_Outptr_ Q** pp)
{
    return QueryInterface(__uuidof(Q), (void **)pp);
}