/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectdefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:10:14 by mobaz             #+#    #+#             */
/*   Updated: 2019/12/20 21:12:01 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _vectdefs_h
#define _vectdefs_h

#if !defined(NDIM) && !defined(TWODIM) && !defined(THREEDIM)
#define THREEDIM                              /* supply default dimensions  */
#endif

#if defined(THREEDIM) || (NDIM==3)
#undef  TWODIM
#define THREEDIM
#define NDIM 3
#endif

#if defined(TWODIM) || (NDIM==2)
#undef  THREEDIM
#define TWODIM
#define NDIM 2
#endif

//typedef real vector[NDIM];
//typedef real matrix[NDIM][NDIM];

#endif  /* ! _vectdefs_h */
