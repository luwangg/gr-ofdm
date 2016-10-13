/* -*- c++ -*- */
/*
 * Copyright 2016 <+YOU OR YOUR COMPANY+>.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */


#ifndef INCLUDED_OFDM_FRAME_ACQUISITION_H
#define INCLUDED_OFDM_FRAME_ACQUISITION_H

#include <ofdm/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace ofdm {

    /*!
     * \brief <+description of block+>
     * \ingroup ofdm
     *
     */
    class OFDM_API frame_acquisition : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<frame_acquisition> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of ofdm::frame_acquisition.
       *
       * To avoid accidental use of raw pointers, ofdm::frame_acquisition's
       * constructor is in a private implementation
       * class. ofdm::frame_acquisition::make is the public interface for
       * creating new instances.
       */
      static sptr make(unsigned occupied_carriers, unsigned int fft_length, unsigned int cplen, const std::vector<gr_complex> &known_symbol, unsigned int max_fft_shift_len);

         /*!
         * \brief Return an estimate of the SNR of the channel
         */
        virtual float snr() = 0;

    };

  } // namespace ofdm
} // namespace gr

#endif /* INCLUDED_OFDM_FRAME_ACQUISITION_H */
