#ifndef _BEBOP_PILOTING_IHM_H_
#define _BEBOP_PILOTING_IHM_H_

#include <curses.h>
#include <libARSAL/ARSAL.h>

typedef enum
{
    IHM_INPUT_EVENT_NONE,
    IHM_INPUT_EVENT_EXIT,
    IHM_INPUT_EVENT_JUMP,
    IHM_INPUT_EVENT_FORWARD,
    IHM_INPUT_EVENT_BACK,
    IHM_INPUT_EVENT_RIGHT,
    IHM_INPUT_EVENT_LEFT,
    IHM_INPUT_EVENT_ASCEND,
    IHM_INPUT_EVENT_DESCEND,
    IHM_INPUT_EVENT_HOVER
}eIHM_INPUT_EVENT;

typedef void (*IHM_onInputEvent_t) (eIHM_INPUT_EVENT event, void *customData);

typedef struct
{
    WINDOW *mainWindow;
    ARSAL_Thread_t inputThread;
    int run;
    IHM_onInputEvent_t onInputEventCallback;
    void *customData;
}IHM_t;

IHM_t *IHM_New (IHM_onInputEvent_t onInputEventCallback);
void IHM_Delete (IHM_t **ihm);

void IHM_setCustomData(IHM_t *ihm, void *customData);

void IHM_PrintHeader(IHM_t *ihm, char *headerStr);
void IHM_PrintInfo(IHM_t *ihm, char *infoStr);
void IHM_PrintBattery(IHM_t *ihm, uint8_t percent);
void IHM_PrintMaxAltitudeStateInfo(IHM_t *ihm, float current, float min, float max);
void IHM_PrintMaxTiltStateInfo(IHM_t *ihm, float current, float min, float max);
void IHM_PrintFlatTrim(IHM_t *ihm, char *infoStr);
void IHM_PrintMaxVerticalSpeedStateInfo(IHM_t *ihm, float current, float min, float max);
void IHM_PrintMaxRotationSpeedStateInfo(IHM_t *ihm, float current, float min, float max);
void IHM_PrintHullProtectionPresence(IHM_t *ihm, char *infoStr);
void IHM_PrintOutdoor(IHM_t *ihm, char *infoStr);
#endif /* _BEBOP_PILOTING_IHM_H_ */