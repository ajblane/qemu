/*
 * QEMU Xtensa CPU
 *
 * Copyright (c) 2012 SUSE LINUX Products GmbH
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Open Source and Linux Lab nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef QEMU_XTENSA_CPU_QOM_H
#define QEMU_XTENSA_CPU_QOM_H

#include "qemu/cpu.h"
#include "cpu.h"

#define TYPE_XTENSA_CPU "xtensa-cpu"

#define XTENSA_CPU_CLASS(class) \
    OBJECT_CLASS_CHECK(XtensaCPUClass, (class), TYPE_XTENSA_CPU)
#define XTENSA_CPU(obj) \
    OBJECT_CHECK(XtensaCPU, (obj), TYPE_XTENSA_CPU)
#define XTENSA_CPU_GET_CLASS(obj) \
    OBJECT_GET_CLASS(XtensaCPUClass, (obj), TYPE_XTENSA_CPU)

/**
 * XtensaCPUClass:
 * @parent_reset: The parent class' reset handler.
 *
 * An Xtensa CPU model.
 */
typedef struct XtensaCPUClass {
    /*< private >*/
    CPUClass parent_class;
    /*< public >*/

    void (*parent_reset)(CPUState *cpu);
} XtensaCPUClass;

/**
 * XtensaCPU:
 * @env: #CPUXtensaState
 *
 * An Xtensa CPU.
 */
typedef struct XtensaCPU {
    /*< private >*/
    CPUState parent_obj;
    /*< public >*/

    CPUXtensaState env;
} XtensaCPU;

static inline XtensaCPU *xtensa_env_get_cpu(const CPUXtensaState *env)
{
    return XTENSA_CPU(container_of(env, XtensaCPU, env));
}

#define ENV_GET_CPU(e) CPU(xtensa_env_get_cpu(e))


#endif
