#ifndef LEARNING_SS_H
#define LEARNING_SS_H
#include "subtraction_algorithm.h"

#include "../learning/learning.hpp"
class LearningSS : public Subtraction
{
	public:
		LearningSS(SubtractionManager& configuration);
		~LearningSS();

		/**
		 * @brief Performs spectral subtraction, simple algorithm.
		 *
		 * @param input_spectrum Input spectrum.
		 * @param noise_power Estimated noise power.
		 */
		virtual void operator()(fftw_complex* input_spectrum, double* noise_spectrum) override;
		virtual void onFFTSizeUpdate() override;
		virtual void onDataUpdate() override;

		/**
		 * @brief Returns alpha.
		 *
		 * @return double alpha.
		 */
		double alpha() const;

		/**
		 * @brief Sets alpha.
		 *
		 * @param value alpha.
		 */
		void setAlpha(double value);

		/**
		 * @brief Returns beta.
		 *
		 * @return double beta.
		 */
		double beta() const;

		/**
		 * @brief Sets beta.
		 *
		 * @param value beta.
		 */
		void setBeta(double value);

	private:
		double computeReward();
		double _previousNRR;

		double* noiselessSignal;

		double _alpha; /**< TODO */
		double _beta; /**< TODO */
		LearningManager learning;

};


#endif // LEARNING_SS_H