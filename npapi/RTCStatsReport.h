/* Copyright(C) 2014-2016 Doubango Telecom <https://github.com/sarandogou/webrtc-everywhere> */
#ifndef _WEBRTC_EVERYWHERE_NPAPI_RTCSTATSREPORT_H_
#define _WEBRTC_EVERYWHERE_NPAPI_RTCSTATSREPORT_H_

#include "../common/_Config.h"
#include "../common/_Common.h"
#include "../common/_AsyncEvent.h"

#include "npapi-includes.h"

class RTCStatsReport
	: public NPObject
	, public _AsyncEventRaiser
	, public _UniqueObject
{
public:
	RTCStatsReport(NPP instance);
	virtual ~RTCStatsReport();

public:
	static NPObject* Allocate(NPP instance, NPClass* npclass);
	static void Deallocate(NPObject* obj);
	static bool HasMethod(NPObject* obj, NPIdentifier methodName);
	static bool InvokeDefault(NPObject* obj, const NPVariant* args,
		uint32_t argCount, NPVariant* result);
	static bool Invoke(NPObject* obj, NPIdentifier methodName,
		const NPVariant* args, uint32_t argCount,
		NPVariant* result);
	static bool HasProperty(NPObject* obj, NPIdentifier propertyName);
	static bool GetProperty(NPObject* obj, NPIdentifier propertyName,
		NPVariant* result);
	static bool SetProperty(NPObject *npobj, NPIdentifier name, const NPVariant *value);
	static bool RemoveProperty(NPObject *npobj, NPIdentifier name);
	static bool NPEnumeration(NPObject *npobj, NPIdentifier **value,
		uint32_t *count);
	static void Invalidate(NPObject *npobj);
	static bool Construct(NPObject *npobj, const NPVariant *args, uint32_t argCount, NPVariant *result);

	NPObjectImpl_CreateInstanceWithRef(RTCStatsReport);
	NPObjectImpl_NPObjectRelease(RTCStatsReport);
	NPObjectImpl_IsInstanceOf(RTCStatsReport);

	WE_INLINE void SetStats(cpp11::shared_ptr<_RTCStatsReport> & states) { m_Stats = states; }
	WE_INLINE cpp11::shared_ptr<_RTCStatsReport> GetStats() { return m_Stats; }

private:
	NPP m_npp;
	cpp11::shared_ptr<_RTCStatsReport> m_Stats;
};

#endif /* _WEBRTC_EVERYWHERE_NPAPI_RTCSTATSREPORT_H_ */
